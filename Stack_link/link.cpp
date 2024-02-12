//
// Created by xiaodian& on 2022/9/30.
//
#include <iostream>
#include "C:\CLionProjects\list2\list2.h"
#include <stdlib.h>

using namespace std;

//注意：这里的很多操作都是假设初始化过的！！！
//所以只要是创建了一个线性链表，一定要直接而初始化！！！
bool List_init(List & list)
{
    list.head=list.rear=NULL;
    list.num=0;
}

bool List_clear(List & list)
{
    if(NULL == list.head){
        cout<<"don't destroy null"<<endl;
        return false;
    }
    Node * p = list.head;
    Node * tem;
    while(p){
        tem=p;
        p=p->next;
        free(tem);
    }
    List_init(list);

    return true;
}

//这里假设都是init过的了
int List_size(List list)
{
    return list.num;
}

//查询链表中第一次出现date的位置，若无，则返回0；
//这里还用了一下重载
int List_find_i(List list, Date date)
{
    Node * p=list.head;
    int idx=0;
    while(p){
        idx++;
        if(p->date == date)
            return idx;
        p=p->next;
    }

    return 0;
}
int List_find_i(List list, PNode p_node)
{
    Node * p=list.head;
    int idx=0;
    while(p){
        idx++;
        if(p == p_node)
            return idx;
        p=p->next;
    }

    return 0;
}

bool List_find_node(List list, int i, PNode & p_node)
{
    if(list.num == 0){
        p_node = NULL;
        return false;
    }
    else if(i<=0 || i>list.num){
        p_node = NULL;
        return false;
    }
    PNode p = list.head;
    i--;
    while(i){
        i--;
        p=p->next;
    }
    p_node = p;

    return true;
}
bool List_find_node(List list, int i, Date & date)
{
    PNode p;
    if(List_find_node(list,i,p)){
        date = p->date;
        return true;
    }

    return false;
}

bool List_add(List & list, Date date)
{
    Node * p = (Node *)malloc(sizeof (Node));
    if(NULL == p){
        cout<<"Maybe there is no memory. Malloc wrong!"<<endl;
        return false;
    }
    p->date=date;
    p->next=NULL;
    if(list.num == 0){
        list.head=p;
        list.rear=p;
    }
    else{
        list.rear->next=p;
        list.rear=p;
    }
    list.num++;

    return true;
}

//因为想从最后加入有add函数，所以这里的idx设置为1<=idx<=num，
//这样也方便实现
bool List_insert(List & list, Date date, int idx)
{
    PNode p = (PNode) malloc(sizeof (Node));
    if(NULL == p){
        cout<<"Maybe there is no memory. Malloc wrong!"<<endl;
        return false;
    }
    if(idx<1 || idx>list.num){
        cout<<"i error(maybe you can use add to add in the rear)"<<endl;
        return false;
    }

    p->date=date;
    if(idx == 1){
        p->next = list.head;
        list.head = p;
        list.num++;
        return true;
    }
    PNode p_prior;
    PNode p_cur;
    List_find_node(list,idx-1,p_prior);
    List_find_node(list,idx,p_cur);
    p_prior->next = p;
    p->next = p_cur;
    list.num++;

    return true;
}

bool List_delete(List & list, int idx, Date & date)
{
    if(idx<1 || idx>list.num){
        cout<<"i error"<<endl;
        return false;
    }
    PNode p_delete;
    PNode p_prior;
    PNode p_next;
    if(idx == 1){
        p_delete = list.head;
        date = p_delete->date;
        list.head = p_delete->next;
        free(p_delete);
        if(list.num == 1)
            list.rear = NULL;
        list.num--;

        return true;
    }

    List_find_node(list,idx-1,p_prior);
    p_delete = p_prior->next;
    p_next = p_delete->next;
    date = p_delete->date;
    p_prior->next=p_next;
    free(p_delete);
    if(idx == list.num)
        list.rear = p_prior;
    list.num--;

    return true;
}

//FIXME:此处因为是基础类型的数据，所以直接用cout了，使用时需要注意
void List_print(List list)
{
    PNode p = list.head;
    if(NULL == p){
        cout<<"It is empty"<<endl;
        return;
    }
    cout<<"[";
    while(p->next){
        cout<<p->date<<" , ";
        p=p->next;
    }
    cout<<p->date<<"]"<<endl;

    return;
}