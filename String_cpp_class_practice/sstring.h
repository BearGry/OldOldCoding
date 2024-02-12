//
// Created by xiaodian& on 2022/10/27.
//

#ifndef STRING_CPP_CLASS_PRACTICE_SSTRING_H
#define STRING_CPP_CLASS_PRACTICE_SSTRING_H

#include "iostream"

using namespace std;

class sstring
{
private:
    char * str;
    int len;
    static const int MAX_SIZE = 244;
    int how_many(const char *);
    void cut(int, int);
    static void get_nextval(const sstring &, int next[]);
public:
    sstring(const char *);
    sstring(const sstring &);
    sstring();
    ~sstring();
    int length() const {return len;}

    sstring & operator=(const sstring &);
    sstring & operator=(const char *);
    char & operator[](int);
    const char & operator[](int) const;

    friend bool operator<(const sstring &, const sstring &);
    friend bool operator>(const sstring &, const sstring &);
    friend bool operator==(const sstring &, const sstring &);
    friend ostream & operator<<(ostream &, const sstring &);
    friend istream & operator>>(istream &, sstring &);

    friend sstring operator+(const sstring &, const sstring &);    //相当于concat

    bool cut(const char *);    //清除里头的所有给定字符串；
    bool cut(const sstring &);
    bool add(int, const char *);    //在给定位置加入某字符串；
    bool add(int, const sstring &);
    int index(const sstring &, int pos = 1) const;    //查找其中的从pos起第一个给定串的位置-KMP算法
    int index(const char *, int pos = 1) const;
    bool replace(const sstring &, const sstring &);        //替换
    sstring operator()(int, int);    //切片--相当于substring

};

#endif //STRING_CPP_CLASS_PRACTICE_SSTRING_H
