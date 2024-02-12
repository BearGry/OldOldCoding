//
// Created by xiaodian& on 2022/10/22.
//

#include <cstdlib>
#include "Stacks.h"
#include "iostream"

using namespace std;

static bool expand(Stack & stack);

bool Init_Stack(Stack & stack)
{
    stack.base = (ElemType *)malloc(BASE_SIZE*sizeof (ElemType));
    if(NULL == stack.base){
        cout<<"Init Stack Error in malloc."<<endl;
        return false;
    }
    stack.stack_size = BASE_SIZE;
    stack.left = -1;
    stack.right = stack.stack_size;

    return true;
}

bool push(Stack & stack, int l_r, ElemType elem)
{
    if(stack.left+1 == stack.right){
        if(!expand(stack)){
            cout<<"The Stack is full. And there is no memory. So push error."<<endl;
            return false;
        }
    }
    if(l_r == 0)
        stack.base[++stack.left] = elem;
    else if(l_r == 1)
        stack.base[--stack.right] = elem;
    else{
        cout<<"For left stack_push - 0, right - 1. Push error."<<endl;
        return false;
    }

    return true;
}

bool pop(Stack & stack, int l_r, ElemType & elem)
{
    if(l_r == 0){
        if(stack.left == -1){
            cout<<"Left_Stack is empty. Pop error."<<endl;
            return false;
        }
        else{
            elem = stack.base[stack.left];
            stack.left--;
            return true;
        }
    }
    else if(l_r == 1){
        if(stack.right == stack.stack_size){
            cout<<"Right_Stack is empty. Pop error."<<endl;
            return false;
        }
        else{
            elem = stack.base[stack.right];
            stack.right++;
            return true;
        }
    }
    else{
        cout<<"For left stack_pop - 0, right - 1. Pop error."<<endl;
        return false;
    }
}

static bool expand(Stack & stack)
{
    ElemType * newbase = (ElemType *) realloc(stack.base,(stack.stack_size+EXPAND)*sizeof (ElemType));
    if(NULL == newbase)
        return false;
    stack.base = newbase;
    for(int i=stack.stack_size-1; i>=stack.right; i--)
        stack.base[i+EXPAND] = stack.base[i];
    stack.right += EXPAND;
    stack.stack_size += EXPAND;

    return true;
}



















