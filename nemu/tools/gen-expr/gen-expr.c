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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

// 生成一个随机数字并将其附加到缓冲区的末尾
static void gen_num() {
    // 生成1到9之间的随机数
    word_t num = rand() % 9 + 1; 
    char num_str[2]; // 临时缓冲区
    snprintf(num_str, sizeof(num_str), "%d", num); // 将数字转化为字符串

    // 检查缓冲区是否有足够的空间
    if (strlen(buf) + strlen(num_str) < sizeof(buf)) {
        strcat(buf, num_str); // 添加到buf末尾
    } 
    
    return; // 缓冲区已满，无法添加更多字
}

void gen_rand_op() {
  if (strlen(buf) + strlen(2) < sizeof(buf))
  {
  switch (rand() % 4) {
    case 0: strcat(buf, " + "); break;
    case 1: strcat(buf, " - "); break;
    case 2: strcat(buf, " * "); break;
    case 3: strcat(buf, " / "); break;
  }
  }
}


int choose(int n) {
  return rand() % n;
}
/ 生成随机表达式
static void gen_rand_expr() {
    switch (choose(3)) {
        case 0: 
            if( buf[strlen(buf) - 1]!=')')
            {
            gen_num(); // 生成随机数字
            }
            else
            {
              gen_rand_expr();
            }
            break;
        case 1: 
              // 避免在操作数之后立即插入左括号，而是在操作符之后插入左括号
            if (buf[0] != '\0' &&  strchr("+-*/", buf[strlen(buf) - 1]))
            {
                strcat(buf, "("); // 将左括号添加到缓冲区末尾
                gen_rand_expr(); // 递归生成随机表达式
                strcat(buf, ")"); // 将右括号添加到缓冲区末尾
            } 
            else 
            {
                gen_rand_expr(); // 递归生成随机表达式
            }
            break;
        default: 
            gen_rand_expr(); // 递归生成随机表达式
            gen_rand_op(); // 生成随机操作符
            gen_rand_expr(); // 递归生成随机表达式
            break;
    }
}
 
 
// 检查表达式中的除零行为
static int check_division_by_zero() {
  char *p = buf;
  while (*p) {
    if (*p == '/' && *(p + 1) == '0') {
      return 1; // 表达式中存在除零行为
    }
    p++;
  }
  return 0; // 表达式中不存在除零行为
}

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i ++) {
    gen_rand_expr();

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    ret = fscanf(fp, "%d", &result);
    pclose(fp);

    printf("%u %s\n", result, buf);
  }
  return 0;
}
