//
// Created by xiaodian& on 2022/10/8.
//

#include "Sqlist.h"
#include <iostream>


using namespace std;

static bool equal(Elemtype a, Elemtype b)
{
    if(a == b)
        return true;
    else
        return false;
}

//初始化顺序表
bool Initsqlist(sq_list &list)
{
    list.elem = (Elemtype *) malloc(SQ_LIST_INIT_SIZE * sizeof (Elemtype));
    if( NULL == list.elem){
        cout<<"Init error"<<endl;
        return false;
    }
    list.length = 0;
    list.listsize = SQ_LIST_INIT_SIZE;

    return true;
}

void Clearlist(sq_list &list)
{
    list.length = 0;
}
//销毁整个顺序表
bool Destroysqlist(sq_list &list)
{
    if(NULL == list.elem){
        cout<<"Don't destroy the null"<<endl;
        return false;
    }
    free(list.elem);

    return true;
}

bool Showsqlist(sq_list &list)
{
    if(list.elem == NULL){
        cout<<"It has not init or has been destroyed"<<endl;
        return false;
    }
    Elemtype * p = list.elem;
    Elemtype * q = list.elem+list.length-1;

    //FIXME:此处用cout因为是基础类型
    for(;p<=q;p++)
        cout<<*p<<"  ";
    cout<<endl;

    return true;
}

//判断是否为空顺序表
bool Sqlistempty(sq_list list)
{
    if(list.length)
        return false;
    else
        return true;
}

//返回顺序表中数据元素的个数
int Sqlistlength(sq_list list)
{
    if(list.elem == NULL){
        cout<<"It has not init or has been destroyed"<<endl;
        return -1;
    }
    else
        return list.length;
}

//获取第i个元素
bool Getelem(sq_list &list, int i, Elemtype &e)
{
    if(list.elem == NULL){
        cout<<"It has not init or has been destroyed"<<endl;
        return false;
    }
    else if(i<0 || i>list.length){
        cout<<"i error"<<endl;
        return false;
    }
    else
        e = list.elem[i-1];

    return true;
}

//compare是数据元素判定函数，用以定位顺序表中第一个
//与e满足compare的元素的位序, 不存在则返回0
int Locateelem(sq_list &list, Elemtype e, bool compare(Elemtype e1, Elemtype e2))
{
    if(list.elem == NULL){
        cout<<"It has not init or has been destroyed"<<endl;
        return 0;
    }

    Elemtype * p = list.elem;
    Elemtype * q = list.elem + list.length -1;
    for(; p<=q; p++){
        if(compare(*p,e))
            return p-list.elem+1;
    }

    return 0;
}

//e是顺序表中且不是第一个的元素，返回他的前驱到pre_e，否则pre_e无定义
bool Priorelem(sq_list &list, Elemtype e, Elemtype &pre_e)
{
    int idx = Locateelem(list,e,equal);
    if(idx<=1)
        return false;
    else{
        pre_e = list.elem[idx-2];
        return true;
    }
}

//e是顺序表中且不是最后一个的元素，返回他的后继到next_e，否则next_e无定义
bool Nextelem(sq_list &list, Elemtype e, Elemtype &next_e)
{
    int idx = Locateelem(list,e,equal);
    if(idx==0 || idx == list.length)
        return false;
    else{
        next_e = list.elem[idx];
        return true;
    }
}

//1<=i<=length+1,使e变为第i个元素
bool Sqlistinsert(sq_list &list, int i, Elemtype e)
{
    if(list.elem == NULL){
        cout<<"It has not init or has been destroyed"<<endl;
        return false;
    }
    else if(i<1 || i>list.length+1){
        cout<<"i error"<<endl;
        return false;
    }
    //此处为扩充
    if(list.length == list.listsize){
        Elemtype * newbase = (Elemtype *) realloc(list.elem,(list.listsize+EXPAND)*sizeof (Elemtype));
        if(!newbase){
            cout<<"sqlist has been full, and can't be expanded"<<endl;
            return false;
        }
        list.elem = newbase;
        list.listsize+=EXPAND;
    }
    Elemtype * p = list.elem+i-1;
    Elemtype * q = list.elem+list.length-1;
    for(;q>=p;q--)
        *(q+1)=*q;
    *p=e;
    list.length++;

    return true;
}

//删除第i个元素（1<=i<=length)
bool Sqlistdelete(sq_list &list, int i, Elemtype &e)
{
    if(list.elem == NULL){
        cout<<"It has not init or has been destroyed"<<endl;
        return false;
    }
    else if(i<1 || i>list.length){
        cout<<"i error"<<endl;
        return false;
    }
    Elemtype * p = list.elem+i-1;
    Elemtype * q = list.elem+list.length-1;
    e=*p;
    for(;p<q;p++)
        *p=*(p+1);
    list.length--;

    return false;
}

//未完待续
bool Sortsqlist(sq_list &list)
{
    return true;
}//排序
bool Unionsqlist(sq_list a, sq_list b, sq_list &c)
{
    return true;
}//两个顺序表的相加