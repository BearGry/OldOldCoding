//
// Created by xiaodian& on 2022/11/3.
//

#ifndef TREE_01_TREE_H
#define TREE_01_TREE_H

#include "iostream"
using namespace std;

template<typename cmp_key, typename content>
class tree {
private:
    typedef struct trnode{
        cmp_key key;
        content data;
        trnode *lchild, *rchild, *parent;
    }trnode, *pnode;

    pnode root;
    int size;

    void destroy(pnode &);
    void copy(pnode &, const pnode &);
    pnode seek(const pnode &t, const cmp_key & key) const
    {
        if(t == nullptr)
            return nullptr;
        if(t->key == key)
            return t;
        if(t->key < key)
            return seek(t->rchild, key);
        return seek(t->lchild, key);
    }
    bool intree(const pnode &, const cmp_key &) const;


public:
    tree();
    ~tree();
    tree(const tree &);
    tree & operator=(const tree &);

    int len(){return size;}
    bool empty(){return (size == 0)? true : false;}


    //此为一些二叉搜索树的基础实现
    bool add(const cmp_key &key, const content &data);             //添加节点
    bool intree(const cmp_key &key) const;    //某数是否在树中
    content &seek(const cmp_key &key) const;     //某数若在，返回节点（结构体）
    bool cut(const cmp_key &key);             //删除某数
    void clear();                           //清空树

    //如果有可以修改，如果没有创建
    content &operator[](const cmp_key &key);

};

////因为树是动态内存分配，所以要进行清除、创建等操作就应该传指针；

template<typename cmp_key, typename content>
inline void tree<cmp_key, content>::destroy(tree::pnode & tree){
    if(tree != nullptr){
        destroy(tree->lchild);
        destroy(tree->rchild);
        delete tree;
    }
}

template<typename cmp_key, typename content>
inline void tree<cmp_key, content>::copy(pnode & tree1,const pnode & tree2){
    if(tree2 != nullptr){
        tree1 = new trnode;
        tree1->key = tree2->key;
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

template<typename cmp_key, typename content>
inline bool tree<cmp_key, content>::intree(const pnode & t, const cmp_key & key) const{
    if(t == nullptr)
        return false;
    if(t->key == key)
        return true;
    if(t->key < key)
        return intree(t->rchild, key);
    return intree(t->lchild, key);
}


template<typename cmp_key, typename content>
tree<cmp_key, content>::tree(){
    root = nullptr;
    size = 0;
}

template<typename cmp_key, typename content>
tree<cmp_key, content>::~tree(){
    destroy(root);
}

template<typename cmp_key, typename content>
tree<cmp_key, content>::tree(const tree & t){
    if(t.root == nullptr){
        root = nullptr;
        size = 0;
        return;
    }
    copy(root,t.root);
    root->parent = nullptr;
    size = t.size;
}

template<typename cmp_key, typename content>
tree<cmp_key, content> &tree<cmp_key, content>::operator=(const tree<cmp_key, content> & t){
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

template<typename cmp_key, typename content>
content &tree<cmp_key, content>::seek(const cmp_key &key) const{
    return seek(root, key)->data;
}

template<typename cmp_key, typename content>
bool tree<cmp_key, content>::intree(const cmp_key & key) const{
    return intree(root,key);
}

template<typename cmp_key, typename content>
bool tree<cmp_key, content>::add(const cmp_key &key, const content &data){
    if(intree(key))
        return true;
    pnode t = new trnode;
    if(t == nullptr)
        return false;
    size++;
    t->key = key;
    t->data = data;
    t->lchild = t->rchild = t->parent = nullptr;
    if(root == nullptr){
        root = t;
        root->parent = nullptr;
        return true;
    }
    pnode p;
    p = root;
    while(1){
        if(p->key < key){
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

template<typename cmp_key, typename content>
bool tree<cmp_key, content>::cut(const cmp_key & key){
    if(intree(key) == false)
        return true;
    size--;
    pnode p = seek(root, key);
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

template<typename cmp_key, typename content>
void tree<cmp_key, content>::clear(){
    destroy(root);
    root = nullptr;
    size = 0;
}

template<typename cmp_key, typename content>
content &tree<cmp_key, content>::operator[](const cmp_key &key) {
    pnode p;
    if(p = seek(root, key))
        return p->data;
    pnode t = new trnode;
    if(t == nullptr)
        exit(0);
    size++;
    t->key = key;
    t->lchild = t->rchild = t->parent = nullptr;
    if(root == nullptr){
        root = t;
        root->parent = nullptr;
        return t->data;
    }
    p = root;
    while(1){
        if(p->key < key){
            if(p->rchild == nullptr){
                p->rchild = t;
                t->parent = p;
                return t->data;

            } else{
                p = p->rchild;
            }
        }else{
            if(p->lchild == nullptr){
                p->lchild = t;
                t->parent = p;
                return t->data;
            } else{
                p = p->lchild;
            }
        }
    }
}

#endif //TREE_01_TREE_H
