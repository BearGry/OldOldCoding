//
// Created by xiaodian& on 2022/10/20.
//

#ifndef QUEUE_LINK_QUEUE_H
#define QUEUE_LINK_QUEUE_H

#include "C:\CLionProjects\list2\list2.h"

typedef struct {
    List data;
}Queue;

bool Queue_init(Queue &);
bool Queue_destroy(Queue &);
bool Queue_empty(Queue);
int Queue_length(Queue);
bool Queue_gethead(Queue &, Date &);
bool Queue_enqueue(Queue &, Date);
bool Queue_dequeue(Queue &, Date &);
bool QueueTraverse(Queue &, bool visit());

#endif //QUEUE_LINK_QUEUE_H
