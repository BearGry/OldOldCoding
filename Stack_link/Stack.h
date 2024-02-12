//
// Created by xiaodian& on 2022/10/20.
//

#ifndef STACK_LINK_STACK_H
#define STACK_LINK_STACK_H

#include "C:\CLionProjects\list2\list2.h"

typedef struct {
    List data;
}Stack;

bool Stack_init(Stack &);
bool Stack_destroy(Stack &);
bool Stack_empty(Stack);
int Stack_length(Stack);
bool Stack_gettop(Stack, Date &);
bool Stack_push(Stack &, Date);
bool Stack_pop(Stack &, Date &);
bool StackTraverse(Stack, bool visit());

#endif //STACK_LINK_STACK_H
