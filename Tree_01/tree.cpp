//
// Created by xiaodian& on 2022/11/3.
//
#include "iostream"
#include "queue"
#include "stack"
#include "tree.h"


using namespace std;
////因为树是动态内存分配，所以要进行清除、创建等操作就应该传指针；

inline void tree::destroy(pnode & tree)
{
    if(tree != nullptr){
        destroy(tree->lchild);
        destroy(tree->rchild);
        delete tree;
    }
}
inline void tree::copy(pnode & tree1,const pnode & tree2)
{
    if(tree2 != nullptr){
        tree1 = new trnode;
        tree1->data = tree2->data;
        copy(tree1->lchild,tree2->lchild);
        copy(tree1->rchild,tree2->rchild);
        if(tree1->rchild != nullptr)
           tree1->rchild->parent = tree1;
        if(tree1->lchild != nullptr)
            tree1->lchild->parent = tree1;
    }
    else
        tree1 = nullptr;
}
inline tree::pnode tree::seek(const pnode & t, const elemtype & elem) const
{
    if(t == nullptr)
        return nullptr;
    if(t->data == elem)
        return t;
    if(t->data < elem)
        return seek(t->rchild, elem);
    return seek(t->lchild, elem);
}
inline bool tree::intree(const pnode & t, const elemtype & elem) const
{
    if(t == nullptr)
        return false;
    if(t->data == elem)
        return true;
    if(t->data < elem)
        return intree(t->rchild, elem);
    return intree(t->lchild, elem);
}
inline void tree::traverse(pnode & t, void visit(elemtype & elem))
{
    if(t != nullptr){
        traverse(t->lchild,visit);
        visit(t->data);
        traverse(t->rchild,visit);
    }
}
inline void tree::pre_show(const pnode & t)
{
    stack<pnode> a;
    a.push(t);
    pnode top;
    while(a.empty() == false){
        top = a.top();
        cout<<top->data<<' ';
        a.pop();
        if(top->rchild != nullptr)
            a.push(top->rchild);
        if(top->lchild != nullptr)
            a.push(top->lchild);
    }
}
inline void tree::ird_show(const pnode & t)
{
    stack<ird> a;
    a.push({t,FIRST});
    ird top;
    while(a.empty() == false){
        top = a.top();
        a.pop();
        if(top.time == SECOND)
            cout<<top.p_node->data<<" ";
        else{
            if(top.p_node->rchild != nullptr)
                a.push({top.p_node->rchild,FIRST});
            a.push({top.p_node,SECOND});
            if(top.p_node->lchild != nullptr)
                a.push({top.p_node->lchild,FIRST});
        }
    }
}
inline void tree::lrd_show(const pnode & t)
{
    stack<lrd> a;
    lrd b;
    b.p_node = t;
    b.time = FIRST;
    a.push(b);
    while (a.empty() == false){
        b = a.top();
        if(b.time == FIRST){
            a.top().time = SECOND;
            if(b.p_node->rchild != nullptr)
                a.push({b.p_node->rchild,FIRST});
            if(b.p_node->lchild != nullptr)
                a.push({b.p_node->lchild,FIRST});
        }else{
            cout<<b.p_node->data<<' ';
            a.pop();
        }
    }
}
inline void tree::BFP(const pnode & t)
{
    queue<pnode> a;
    a.push(t);
    pnode b;
    while(a.empty() == false){
        b = a.front();
        cout<<b->data<<' ';
        a.pop();
        if(b->lchild != nullptr)
            a.push(b->lchild);
        if(b->rchild != nullptr)
            a.push(b->rchild);
    }
}
void tree::pre_show_recursion(const pnode & t)
{
    if(t != nullptr){
        cout<<t->data<<" ";
        pre_show_recursion(t->lchild);
        pre_show_recursion(t->rchild);
    }
}
void tree::ird_show_recursion(const pnode & t)
{
    if(t != nullptr){
        ird_show_recursion(t->lchild);
        cout<<t->data<<" ";
        ird_show_recursion(t->rchild);
    }
}
void tree::lrd_show_recursion(const pnode & t)
{
    if(t != nullptr){
        lrd_show_recursion(t->lchild);
        lrd_show_recursion(t->rchild);
        cout<<t->data<<" ";
    }
}

inline int tree::nodes(const pnode & t) {
     if(t == nullptr)
         return 0;
     if(t->lchild == nullptr && t->rchild == nullptr)
         return 1;
     return nodes(t->lchild)+ nodes(t->rchild);
}
inline int tree::deep(const pnode & t) {
    if(t == nullptr)
        return 0;
    if(t->lchild == nullptr && t->rchild == nullptr)
        return 1;
    return 1+max(deep(t->lchild), deep(t->rchild));
}
inline bool tree::similar(const pnode & p, const pnode & q) {
    if(p == nullptr && q == nullptr)
        return true;
    if(p == nullptr && q != nullptr || p != nullptr && q == nullptr)
        return false;
    return similar(p->lchild,q->lchild) && similar(p->rchild,q->rchild);
}
inline void tree::reverse(const pnode & t) {
    if(t == nullptr)
        return;
    swap(t->lchild,t->rchild);
    reverse(t->lchild);
    reverse(t->rchild);
}


tree::tree()
{
    root = nullptr;
    size = 0;
}
tree::~tree()
{
    destroy(root);
}
tree::tree(const tree & t)
{
    if(t.root == nullptr){
        root = nullptr;
        size = 0;
        return;
    }
    copy(root,t.root);
    root->parent = nullptr;
    size = t.size;
}
tree & tree::operator=(const tree & t)
{
    if(this == &t)
        return *this;
    destroy(root);
    if(t.root == nullptr){
        root = nullptr;
        size = 0;
        return *this;
    }
    copy(root,t.root);
    root->parent = nullptr;
    size = t.size;
    return *this;
}

tree::pnode tree::seek(const elemtype & elem) const
{
    return seek(root,elem);
}

bool tree::intree(const elemtype & elem) const
{
    return intree(root,elem);
}

bool tree::add(const elemtype & elem)
{
    if(intree(elem))
        return true;
    pnode t = new trnode;
    if(t == nullptr)
        return false;
    size++;
    t->data = elem;
    t->lchild = t->rchild = t->parent = nullptr;
    if(root == nullptr){
        root = t;
        root->parent = nullptr;
        return true;
    }
    pnode p;
    p = root;
    while(1){
        if(p->data < elem){
            if(p->rchild == nullptr){
                p->rchild = t;
                t->parent = p;
                return true;
            } else{
                p = p->rchild;
            }
        }else{
            if(p->lchild == nullptr){
                p->lchild = t;
                t->parent = p;
                return true;
            } else{
                p = p->lchild;
            }
        }
    }
}

bool tree::cut(const elemtype & elem)
{
    if(intree(elem) == false)
        return true;
    size--;
    pnode p = seek(elem);
    pnode p_parent = p->parent;
    if(p_parent == nullptr){
        if(p->lchild == nullptr && p->rchild == nullptr){
            root = nullptr;
        }else if(p->lchild == nullptr){
            root = p->rchild;
            root->parent = nullptr;
        }else if(p->rchild == nullptr){
            root = p->lchild;
            root->parent = nullptr;
        }else{
            pnode t = p->lchild;
            while (t->rchild){
                t = t->rchild;
            }
            t->rchild = p->rchild;
            root = p->lchild;
            root->parent = nullptr;
        }
        delete p;
        return true;
    }
    if(p->lchild == nullptr){
        if(p_parent->lchild == p){
            p_parent->lchild = p->rchild;
        } else{
            p_parent->rchild = p->rchild;
        }
        delete p;
    } else if(p->rchild == nullptr){
        if(p_parent->lchild == p){
            p_parent->lchild = p->lchild;
        } else{
            p_parent->rchild = p->lchild;
        }
        delete p;
    } else{
        pnode t = p->lchild;
        while(t->rchild){
            t = t->rchild;
        }
        t->rchild = p->rchild;
        if(p_parent->lchild == p){
            p_parent->lchild = p->lchild;
        } else{
            p_parent->rchild = p->lchild;
        }
        delete p;
    }
    return true;
}

void tree::traverse(void visit(elemtype & elem))
{
    traverse(root,visit);
}

void tree::clear()
{
    destroy(root);
    root = nullptr;
    size = 0;
}

void tree::display()
{
    if(size == 0)
        return;
    cout<<"PreOrder_Display:"<<endl;
    pre_show(root);
    cout<<endl;
    cout<<"InOrder_Display:"<<endl;
    ird_show(root);
    cout<<endl;
    cout<<"LrdOrder_Display:"<<endl;
    lrd_show(root);
    cout<<endl;
    cout<<"BFP_Display:"<<endl;
    BFP(root);
    cout<<endl;
}

void tree::display_recursion()
{
    if(size == 0)
        return;
    cout<<"PreOrder_Display:"<<endl;
    pre_show_recursion(root);
    cout<<endl;
    cout<<"InOrder_Display:"<<endl;
    ird_show_recursion(root);
    cout<<endl;
    cout<<"LrdOrder_Display:"<<endl;
    lrd_show_recursion(root);
    cout<<endl;
    cout<<"BFP_Display:"<<endl;
    BFP(root);
    cout<<endl;
}

bool tree::complete() {
    pnode a[size];
    int rear;
    int front;
    front = rear = -1;
    a[++rear] = root;
    int count = 1;
    while(count < size){
        pnode p = a[++front];
        if(p->lchild == nullptr)
            return false;
        else{
            a[++rear] = p->lchild;
            count++;
        }
        if(p->rchild == nullptr){
            if(count == size)
                return true;
            else
                return false;
        }
        else{
            a[++rear] = p->rchild;
            count++;
        }
    }
    return true;
}

int tree::nodes() {
    return nodes(root);
}
int tree::deep() {
    return deep(root);
}
bool tree::similar(const tree & t) {
    if(size == t.size)
        return similar(root,t.root);
    return false;
}
void tree::reverse() {
    reverse(root);
}

istream & operator>>(istream & cin, tree & t)
{
    cout<<"How many node do you want to add: ";
    int n;
    cin>>n;
    if(n == 0){
        cout<<"Ok."<<endl;
        return cin;
    }
    cout<<"Then input the node_value:"<<endl;
    elemtype elem;
    for(int i=1; i<=n; i++){
        cin>>elem;
        t.add(elem);
    }
    return cin;
}
ostream & operator<<(ostream & cout, tree & t)
{
    t.traverse(t.root,t.show);
    return cout;
}


//判断是不是排序树
bool tree::inorder() {
    if(root == nullptr)
        return true;
    ird stack[size];
    int top = -1;
    stack[++top] = {root,FIRST};
    elemtype last = root->data;
    bool first = true;
    ird a;
    while(top>=0){
        a = stack[top--];
        if(a.time == FIRST){
            if(a.p_node->rchild != nullptr)
               stack[++top] = {a.p_node->rchild,FIRST};
            stack[++top] = {a.p_node,SECOND};
            if(a.p_node->lchild != nullptr)
               stack[++top] = {a.p_node->lchild,FIRST};
        }
        else{
            if(a.p_node->data > last){
                last = a.p_node->data;
                continue;
            }
            if(first){
                first = false;
                last = a.p_node->data;
                continue;
            }
            return false;
        }
    }
    return true;
}



//输出不小于给定数（从大到小序列）
void tree::show_key(const tree::pnode &t, const elemtype &a) {
    if(t == nullptr)
        return;
    show_key(t->rchild,a);
    if(t->data > a){
        cout<<t->data<<" ";
        show_key(t->lchild,a);
    }
    else if(t->data == a)
        cout<<t->data<<" ";
}
void tree::show_key(const elemtype &a) {
    show_key(root,a);
}

//两树相加
void tree::add_tree(const tree::pnode & t) {
    if(t == nullptr)
        return;
    add(t->data);
    add_tree(t->lchild);
    add_tree(t->rchild);
}
tree tree::operator+(const tree & t) {
    tree c = t;
    c.add_tree(root);
    return c;
}












































































































































