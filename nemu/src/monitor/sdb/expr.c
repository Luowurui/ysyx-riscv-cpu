/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <memory/paddr.h>
/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

enum {
  TK_NOTYPE = 256, TK_EQ,TK_AND,TK_NEQ,
  TK_NUM, TK_HEX,TK_NEG,TK_REG,TK_DEREF,

  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */
  {" +", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  {"-", '-'},           // minus
  {"\\*", '*'},         // multiply
  {"/", '/'},           // divide
  {"\\(", '('},         // left parenthesis
  {"\\)", ')'},         // right parenthesis
  {"==", TK_EQ},         // equal
  {"!=", TK_NEQ},       // not equal
  {"&&", TK_AND},       // logical and
  {"0x[0-9a-fA-F]+", TK_HEX}, // hexadecimal number
  {"\\$[a-zA-Z_][a-zA-Z0-9_]*", TK_REG}, // register name
  {"[0-9]+", TK_NUM},   // numbers 
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;//指示已被识别出的token数目

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

         if (rules[i].token_type != TK_NOTYPE) {
          tokens[nr_token].type = rules[i].token_type;//记录type名
          if (tokens[nr_token].type == '-') {  // 是负号判断
            if (nr_token == 0 || (tokens[nr_token-1].type != TK_NUM && tokens[nr_token-1].type != ')')) {
              tokens[nr_token].type = TK_NEG;  
            }
          if (tokens[nr_token].type == '*') {  // 指针判断
            if (nr_token == 0 || (tokens[nr_token-1].type != TK_NUM && tokens[nr_token-1].type != ')')) {
              tokens[nr_token].type = TK_DEREF;  
            }
            }
          }
        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
          case TK_NOTYPE:break;
          case TK_NUM:
          case TK_HEX:
            strncpy(tokens[nr_token].str,substr_start,substr_len > 31 ? 31 : substr_len);
            tokens[nr_token].str[substr_len > 31 ? 31 : substr_len] = '\0';
            nr_token++;
            break;
          case TK_REG:
            strncpy(tokens[nr_token].str,substr_start+1,substr_len > 31 ? 31 : substr_len);
            tokens[nr_token].str[substr_len > 31 ? 31 : substr_len] = '\0';
            nr_token++;
            break;
          default: 
            nr_token++;
            break;
        }

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
    }
  }
  return true;
}

bool check_parentheses(int p, int q) {
  if (tokens[p].type != '(' || tokens[q].type != ')') {
    return false;
  }//外部没括号
  int count = 0;
  int left = 0;//用以避免出现(1+1)误判的情况
  for (int i = p ; i < q; i++) {
    if (tokens[i].type == '(') {count++;left++;}
    if (tokens[i].type == ')') count--;
    if (count < 0) assert(0);//return false;//括号不匹配
  }
    
  if ((tokens[p+1].type != '(' || tokens[q-1].type != ')') && left >1) 
    return false;//没有外部大括号,(1+1)*(1+1),直接拆成两个狮子
  return true;//正常
}
//优先级最低的运算符为住运算符
int find_dominant_op(int p, int q) {
  int op = -1;
  int level = 0;
  for (int i = p; i <= q; i++) {
    if (tokens[i].type == '(') level++;
    if (tokens[i].type == ')') level--;
    if (level == 0) {
      if (tokens[i].type == '+' || tokens[i].type == '-') {
        op = i;
      } else if ((tokens[i].type == '*' || tokens[i].type == '/') && op == -1) {
        op = i;
      }
    }
  }
  return op;
}

word_t eval(int p,int q){
  if (p > q) {
    /* Bad expression */
    assert(0);return -1;
  }
  else if (p == q) {
    /* Single token.
     * For now this token should be a number.
     * Return the value of the number.
     */
    if (tokens[p].type == TK_NUM) {
      return atoi(tokens[p].str);
    }
    else if (tokens[p].type == TK_HEX) {
      return strtol(tokens[p].str, NULL, 16);
    }
   // else if (tokens[p].type == TK_REG) {
    else{
      return isa_reg_str2val(tokens[p].str,NULL);
    }

  }

  else if (tokens[p].type == TK_DEREF) {
    return paddr_read((eval(p + 1, q)),4);
  }

  else if (tokens[p].type == TK_NEG)
  {
    return -eval(p+1,q);
  }
  else if (check_parentheses(p, q) == __GCC_ATOMIC_TEST_AND_SET_TRUEVAL) {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    return eval(p + 1, q - 1);
  } 
  else {
    int op = find_dominant_op(p,q);
    word_t val1 = eval(p, op - 1);
    word_t val2 = eval(op + 1, q);

    switch (tokens[op].type) {
      case '+': return val1 + val2;break;
      case '-': return val1 - val2;break;
      case '*': return val1 * val2;break;
      case '/': return val1 / val2;break;
      case TK_EQ: return val1 == val2;break;
      case TK_NEQ: return val1 != val2;break;
      case TK_AND: return val1 && val2;break;
      default: assert(0);return -1;
    }
  }
}

word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
  //TODO();
  *success = true;
  return eval(0,nr_token-1);
}
