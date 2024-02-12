//
// Created by xiaodian& on 2022/12/1.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <cstdlib>

template<typename type>
class vector {
private:
    type * base;
    int size;
    int len;
    enum {INIT_SIZE = 14, EXPAND = 5};

    void expand();
public:
    vector(int n = INIT_SIZE);
    ~vector();
    vector(const vector & v);
    vector & operator=(const vector & v);

    bool empty() const {return len==0;}
    int length() const {return len;}

    type & operator[](int i);
    const type & operator[](int i) const;
    void push(const type & t);
};

template<typename type>
void vector<type>::expand() {
    type * newbase = new type[size+EXPAND];
    if(newbase == nullptr)
        exit(0);
    for(int i=0; i<len; i++)
        newbase[i] = base[i];
    delete [] base;
    base = newbase;
    size = size + EXPAND;
}

template<typename type>
vector<type>::vector(int n) {
    base = new type[n];
    len = 0;
    size = n;
}

template<typename type>
vector<type>::~vector() {
    delete [] base;
}

template<typename type>
vector<type>::vector(const vector<type> &v) {
    len = v.len;
    size = v.size;
    base = new type[size];
    for(int i=0; i<v.len; i++)
        base[i] = v.base[i];
}

template<typename type>
vector<type> & vector<type>::operator=(const vector<type> &v) {
    if(this == &v)
        return *this;
    delete [] base;
    len = v.len;
    size = v.size;
    base = new type[size];
    for(int i=0; i<v.len; i++)
        base[i] = v.base[i];
    return *this;
}

template<typename type>
void vector<type>::push(const type &t) {
    if(len == size)
        expand();
    base[len++] = t;
}

template<typename type>
type &vector<type>::operator[](int i) {
    ////这里假设i的值均正确，即i可以访问已有的那一部分
    ////这个用于修改，const版用以访问，添加的话用push函数，这个不可以添加；
    if(len == 0)
        exit(0);
    i = (i>0)? i : -i;
    return base[(i%len)];
}

template<typename type>
const type &vector<type>::operator[](int i) const {
    if(len == 0)
        exit(0);
    i = (i>0)? i : -i;
    return base[(i%len)];
}

#endif //VECTOR_VECTOR_H
