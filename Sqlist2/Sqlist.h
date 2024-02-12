//
// Created by xiaodian& on 2022/10/8.
//

#ifndef SQLIST2_SQLIST_H
#define SQLIST2_SQLIST_H

#define SQ_LIST_INIT_SIZE 100
#define EXPAND 10

typedef int Elemtype;

typedef struct {
    Elemtype *elem;
    int length;    //数据长度
    int listsize;  //存储长度-分配空间
} sq_list;

bool Initsqlist(sq_list &list);
void Clearsqlist(sq_list &list);
bool Destroysqlist(sq_list &list);
bool Showsqlist(sq_list &list);
bool Sqlistempty(sq_list list);
int Sqlistlength(sq_list list);
bool Getelem(sq_list &list, int i, Elemtype &e);
int Locateelem(sq_list &list, Elemtype e, bool compare(Elemtype e1, Elemtype e2));
bool Priorelem(sq_list &list, Elemtype e, Elemtype &pre_e);
bool Nextelem(sq_list &list, Elemtype e, Elemtype &next_e);
bool Sqlistinsert(sq_list &list, int i, Elemtype e);
bool Sqlistdelete(sq_list &list, int i, Elemtype &e);


//未完待续
bool Sortsqlist(sq_list &list);//排序
bool Unionsqlist(sq_list a, sq_list b, sq_list &c);//两个顺序表的相加

#endif //SQLIST2_SQLIST_H
