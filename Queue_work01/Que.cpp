//
// Created by xiaodian& on 2022/10/22.
//
#include <iostream>
#include <cstdlib>
#include "Que.h"

using namespace std;

bool Init_Queue(Queue & queue)
{
    queue.rear = (pLnode)malloc(sizeof (Lnode));
    if(NULL == queue.rear){
        cout<<"Init error."<<endl;
        return false;
    }
    queue.rear->next = queue.rear;
    queue.num = 0;

    return true;
}

bool Enqueue(Queue & queue, Elemtype a)
{
    Lnode * p = (pLnode)malloc(sizeof (Lnode));
    if(NULL == p){
        cout<<"Enqueue error in malloc."<<endl;
        return false;
    }
    p->data = a;

    p->next = queue.rear->next;
    queue.rear->next = p;
    queue.rear = p;

    queue.num++;

    return true;
}

bool Dequeue(Queue & queue, Elemtype & a)
{
    if(0 == queue.num){
        cout<<"The queue is empty. Dequeue error."<<endl;
        return false;
    }

    pLnode head = queue.rear->next;
    pLnode p = head->next;
    a = p->data;
    head->next = p->next;
    free(p);
    queue.num--;

    if(0 == queue.num)
        queue.rear = head;

    return true;
}




















