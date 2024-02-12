//
// Created by xiaodian& on 2022/10/20.
//
#include <iostream>
#include "Queue.h"

using namespace std;

bool Queue_init(Queue & queue)
{
    return List_init(queue.data);
}

bool Queue_destroy(Queue & queue)
{
    return List_clear(queue.data);
}

bool Queue_empty(Queue queue)
{
    int num = List_size(queue.data);
    if(num)
        return false;
    else
        return true;
}

int Queue_length(Queue queue)
{
    return List_size(queue.data);
}

bool Queue_gethead(Queue & queue, Date & e)
{
    if(Queue_empty(queue)){
        cout<<"It is empty. So gethead error."<<endl;
        return false;
    }
    return List_find_node(queue.data,1,e);
}

bool Queue_enqueue(Queue & queue, Date e)
{
    return List_add(queue.data,e);
}

bool Queue_dequeue(Queue & queue, Date & e)
{
    if(Queue_empty(queue)){
        cout<<"It is empty. So dequeue error."<<endl;
        return false;
    }
    return List_delete(queue.data,1,e);
}

bool QueueTraverse(Queue &, bool visit())
{
    return false;
}























