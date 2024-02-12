//
// Created by xiaodian& on 2022/10/22.
//

#ifndef TWO_HEAD_STACK_STACKS_H
#define TWO_HEAD_STACK_STACKS_H

#define BASE_SIZE 5
#define EXPAND 10

typedef int ElemType;
typedef struct {
    ElemType * base;
    int stack_size;
    int left;
    int right;
}Stack;

bool Init_Stack(Stack &);
bool push(Stack &, int, ElemType);
bool pop(Stack &, int, ElemType &);

#endif //TWO_HEAD_STACK_STACKS_H
