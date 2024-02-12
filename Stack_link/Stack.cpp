//
// Created by xiaodian& on 2022/10/20.
//
#include <iostream>
#include "Stack.h"

using namespace std;

bool Stack_init(Stack & stack)
{
    return List_init(stack.data);
}

bool Stack_destroy(Stack & stack)
{
    return List_clear(stack.data);
}

bool Stack_empty(Stack stack)
{
    int num = List_size(stack.data);
    if(!num)
        return true;
    else
        return false;
}

int Stack_length(Stack stack)
{
    return List_size(stack.data);
}

bool Stack_gettop(Stack stack, Date & e)
{
    if(Stack_empty(stack)){
        cout<<"There is nothing in the stack, so gettop error."<<endl;
        return false;
    }
    List_find_node(stack.data, List_size(stack.data),e);

    return true;
}

bool Stack_push(Stack & stack, Date e)
{
    return List_add(stack.data,e);
}

bool Stack_pop(Stack & stack, Date & e)
{
    if(!Stack_empty(stack))
        return List_delete(stack.data, List_size(stack.data), e);
    return false;
}

bool StackTraverse(Stack, bool visit())
{
    return false;
}



















