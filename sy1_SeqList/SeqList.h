//
// Created by xiaodian& on 2022/10/29.
//

#ifndef SY1_SEQLIST_SEQLIST_H
#define SY1_SEQLIST_SEQLIST_H

#include "iostream"
using std::ostream;

#define EXPAND 15
#define INIT_SIZE 140
typedef int ElemType;

class SeqList
{
private:
    ElemType *base;
    int length;
    int size;
    void expand();
public:
    SeqList(int n = INIT_SIZE);
    SeqList(const SeqList &);
    ~SeqList();
    SeqList & operator=(const SeqList &);

    int len() {return length;}
    bool insert(int, const ElemType &);
    bool add(const ElemType &);
    bool dele(int, ElemType &);
    bool dele(int);
    void clear() {length = 0;}
    ElemType & operator[](int);
    const ElemType & operator[](int) const;

    void revert();
    void add_sq(const ElemType &);
    void sort();

    friend SeqList operator+(const SeqList &, const SeqList &);
    friend SeqList operator^(const SeqList &, const SeqList &);
    friend ostream & operator<<(ostream &, const SeqList &);
};


#endif //SY1_SEQLIST_SEQLIST_H
