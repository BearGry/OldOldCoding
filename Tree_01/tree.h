//
// Created by xiaodian& on 2022/11/3.
//

#ifndef TREE_01_TREE_H
#define TREE_01_TREE_H
#include "iostream"

using namespace std;
typedef int elemtype;

class tree {
private:
    typedef struct trnode{
        elemtype data;
        trnode *lchild, *rchild, *parent;
    }trnode, *pnode;
    typedef enum {FIRST,SECOND} TIME;
    typedef struct lrd{
        pnode p_node;
        TIME time;
    }lrd,ird;
    void destroy(pnode &);
    void copy(pnode &, const pnode &);
    pnode seek(const pnode &, const elemtype &) const;
    bool intree(const pnode &, const elemtype &) const;
    void traverse(pnode &, void visit(elemtype &));

    static void show(elemtype & elem) {cout<<elem<<' ';}

    void pre_show(const pnode &);
    void ird_show(const pnode &);
    void lrd_show(const pnode &);
    void BFP(const pnode &);
    void pre_show_recursion(const pnode &);
    void ird_show_recursion(const pnode &);
    void lrd_show_recursion(const pnode &);

    int nodes(const pnode &);
    int deep(const pnode &);
    bool similar(const pnode &, const pnode &);
    void reverse(const pnode &);

    void show_key(const pnode & t, const elemtype & a);
    void add_tree(const pnode &);

    pnode root;
    int size;

public:
    tree();
    ~tree();
    tree(const tree &);
    tree & operator=(const tree &);

    int len(){return size;}
    bool empty(){return (size == 0)? true : false;}
    int nodes();
    int deep();
    bool add(const elemtype &);             //添加节点
    bool intree(const elemtype &) const;    //某数是否在树中
    pnode seek(const elemtype &) const;     //某数若在，返回节点（结构体）
    bool cut(const elemtype &);             //删除某数
    void traverse(void visit(elemtype &));  //遍历操作,执行visit函数；
    void display();                         //四种顺序展示 非递归实现
    void display_recursion();               //先、中、后序递归实现
    void clear();                           //清空树
    bool complete();
    bool similar(const tree &);
    void reverse();

    bool inorder();
    void show_key(const elemtype & a);
    tree operator+(const tree &);

    friend istream & operator>>(istream &, tree &);  //输入树，第一个数为想加多少个
    friend ostream & operator<<(ostream &, tree &);  //递增展示树
};


#endif //TREE_01_TREE_H
