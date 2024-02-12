//
// Created by xiaodian& on 2022/9/30.
//

#ifndef LIST2_LIST2_H
#define LIST2_LIST2_H

typedef int Date;
typedef struct Node{
    Date date;
    Node * next;
}Node,*PNode;
typedef struct {
    Node * head;
    Node * rear;
    int num;
}List;

bool List_init(List &);
bool List_clear(List &);

int List_size(List);

int List_find_i(List, Date);
int List_find_i(List, PNode);
bool List_find_node(List, int , PNode &);
bool List_find_node(List, int, Date &);

bool List_add(List &, Date);
bool List_insert(List &, Date , int);
bool List_delete(List &, int , Date &);

void turn_over(List &);

void List_print(List);

#endif //LIST2_LIST2_H
