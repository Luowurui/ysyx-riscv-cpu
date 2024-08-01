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

#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  char expr[256]; // 用于存储被监视的表达式
  word_t last_value; // 用于存储上次计算的值
  /* TODO: Add more members if necessary */

} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */
WP* new_wp(){
  if (free_ == NULL) {
      printf("No free watchpoints available!\n");
      return NULL;
    }

  WP *wp = free_;
  free_ = free_->next;

  wp->next = head;
  head = wp;

  return wp;
}

void free_wp(WP *wp){
  WP *prev = NULL;
  WP *curr = head;

  while (curr != NULL && curr != wp) {
    prev = curr;
    curr = curr->next;
  }

  if (curr == NULL) {
    printf("Watchpoint not found!\n");
    return;
  }

  if (prev == NULL) {
    head = curr->next;//头结点
  } else {
    prev->next = curr->next;
  }

  curr->next = free_;
  free_ = curr;//释放的节点插入到链表头部
}

static int no=1;
void wp_add(char *e) {
  WP *wp = new_wp();
  if (wp == NULL) {
    return;
  }

  strncpy(wp->expr, e, sizeof(wp->expr) - 1);
  wp->expr[sizeof(wp->expr) - 1] = '\0';
  wp->NO = no;
  bool success;
  word_t result=expr(e, &success);
  if (!success) {
    printf("Failed to evaluate expression: %s\n", e);
    free_wp(wp);
    return;
  }
  wp->last_value = result;
  printf("Watchpoint %d: %s = %d\n", wp->NO, wp->expr,result);
  no++;
} 

void wp_del(int no) {
  WP *wp = head;
  while (wp != NULL) {
    if (wp->NO == no) {
      free_wp(wp);
      printf("Watchpoint %d deleted\n", no);
      return;
    }
    wp = wp->next;
  }
  printf("No watchpoint number %d found\n", no);
}

void wp_info()
{
  WP *pos=head;
  if(!pos)
  {
    printf("NO watchpoints");
    return;
  }
   printf("%-8s%-8s\n", "No", "Expression");
  while (pos) {
    printf("%-8d%-8s\n", pos->NO, pos->expr);
    pos = pos->next;
  }
}

void wp_difftest(){
  // 添加检查监视点的逻辑
  WP *wp = head;
  for (int i = 0; i < NR_WP; i ++) {
    word_t new_value;
    bool success;
    new_value= expr(wp->expr, &success);
    if (!success) {
      printf("Failed to evaluate expression: %s\n", wp->expr);
      return;
    }
    if (new_value !=  wp_pool[i].last_value) {
      printf("Watchpoint %d triggered: %s\n", wp_pool[i].NO, wp_pool[i].expr);
      printf("Old value: %d\n", wp_pool[i].last_value);
      printf("New value: %d\n", new_value);
      wp_pool[i].last_value = new_value;
      nemu_state.state = NEMU_STOP;
      return;
    }
  }
}