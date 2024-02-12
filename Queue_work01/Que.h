//
// Created by xiaodian& on 2022/10/22.
//

#ifndef QUEUE_WORK01_QUE_H
#define QUEUE_WORK01_QUE_H

typedef int Elemtype;
typedef struct Lnode{
    Elemtype data;
    Lnode * next;
}Lnode,*pLnode;

typedef struct {
    pLnode rear;
    int num;
}Queue;

bool Init_Queue(Queue &);
bool Enqueue(Queue &, Elemtype);
bool Dequeue(Queue &, Elemtype &);

#endif //QUEUE_WORK01_QUE_H
