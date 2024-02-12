//
// Created by xiaodian& on 2022/10/27.
//
#include "iostream"
#include "sstring.h"

using namespace std;

inline void sstring::get_nextval(const sstring & t, int next[]) {
    next[0] = -1;
    int i = 0;
    int j = -1;
    int end = t.len - 1;
    while (i < end) {
        if (j == -1 || t.str[i] == t.str[j]) {
            i++;
            j++;
            if (t.str[i] == t.str[j]) next[i] = next[j];
            else next[i] = j;
        } else
            j = next[j];
    }
}

inline int sstring::how_many(const char * a)
{
    int len = 0;
    int i = 0;
    while (a[i++] != '\0')
        ++len;
    return len;
}

inline void sstring::cut(int pos, int lens)
{
    int begin = pos-1+lens;
    int end = len;
    for(int i=begin; i<end; i++)
        str[i-lens] = str[i];
    len -= lens;
    char ch[len+1];
    for(int i=0; i<len; i++)
        ch[i] = str[i];
    ch[len]='\0';
}

sstring::sstring(const char * a)
{
    len = how_many(a);
    str = new char [len];
    for (int i = 0; i < len; i++)
        str[i] = a[i];
}
sstring::sstring(const sstring & t)
{
    len = t.len;
    str = new char [len];
    for(int i = 0; i<len; i++)
        str[i] = t.str[i];
}
sstring::sstring()
{
    len = 5;
    str = new char [5];
    str[0]='h'; str[1]='e'; str[2]='l'; str[3]='l'; str[4]='o';
}
sstring::~sstring()
{
    if(str == nullptr)
        return;
    len = 0;
    delete [] str;
}


sstring & sstring::operator=(const sstring & t)
{
    if(this == &t)
        return *this;
    delete [] str;
    len = t.len;
    str = new char [len];
    for(int i = 0; i<len; i++)
        str[i] = t.str[i];
    return *this;
}
sstring & sstring::operator=(const char * t)
{
    delete [] str;
    len = how_many(t);
    str = new char [len];
    for(int i = 0; i<len; i++)
        str[i] = t[i];
    return *this;
}

char & sstring::operator[](int i)
{
    return str[i];
}
const char & sstring::operator[](int i) const
{
    return str[i];
}

bool operator<(const sstring & s, const sstring & t)
{
    int i=0,j=0;
    int s_len=s.len,t_len=t.len;
    while(i<s_len && j<t_len){
        if(s.str[i] > t.str[j])
            return true;
        else if(s.str[i] < t.str[j])
            return false;
        else{
            i++; j++;
        }
    }
    if(s_len == t_len)
        return false;
    else if(s_len < t_len)
        return false;
    else
        return true;
}
bool operator>(const sstring & s, const sstring & t)
{
    return t<s;
}
bool operator==(const sstring & s, const sstring & t)
{
    if(t<s || s<t)
        return false;
    return true;
}

ostream & operator<<(ostream & cout, const sstring & s)
{
    cout<<"\"";
    for(int i=0,end=s.len; i<end; i++)
        cout<<s.str[i];
    cout<<"\"";
    return cout;
}
istream & operator>>(istream & cin, sstring & s)
{
    char temp[sstring::MAX_SIZE];
    cin.get(temp,sstring::MAX_SIZE);
    if(!cin){
        cout<<">> error!"<<endl;
        exit(0);
    }
    s = temp;
    while (cin && cin.get()!='\n')
        continue;
    return cin;
}

sstring operator+(const sstring & a, const sstring & b)    //相当于concat
{
    int len = a.len + b.len;
    char ch[len+1];
    int i;
    for (i = 0; i < a.len; i++)
        ch[i] = a.str[i];
    for (int j = 0; j < b.len; j++)
        ch[i++] = b.str[j];
    ch[len] = '\0';
    sstring c(ch);

    return c;
}

bool sstring::replace(const sstring & a, const sstring & b)//替换
{
    int pos = 1;
    pos = index(a,pos);
    while (pos){
        cut(pos,a.len);
        add(pos,b);
        pos = index(a,pos+b.len);
    }
    return true;
}

bool sstring::cut(const char * a)    //清除里头的所有给定字符串；
{
    int pos = 1;
    pos = index(a,pos);
    while (pos){
        cut(pos, how_many(a));
        pos = index(a,pos);
    }
    return true;
}
bool sstring::cut(const sstring & t)
{
    int pos = 1;
    pos = index(t,pos);
    while (pos){
        cut(pos, t.len);
        pos = index(t,pos);
    }
    return true;
}

bool sstring::add(int pos, const char * a)    //在给定位置加入某字符串；
{
    return add(pos,sstring(a));
}

bool sstring::add(int pos, const sstring & t)
{
    if(pos<1 || pos > len+1)
        return false;
    if(len == 0){
        *this = t;
        return true;
    }
    char ch[len+t.len+1];
    for(int i=0; i<len; i++)
        ch[i] = str[i];
    for(int i=len-1,end=pos-1,lens=t.len; i>=end; i--)
        ch[i+lens] = ch[i];
    for(int i=pos-1,end=pos-1+t.len,j=0; i<end; i++)
        ch[i] = t.str[j++];
    ch[len+t.len] = '\0';
    *this = ch;

    return true;
}

int sstring::index(const char * ch, int pos) const
{
    return index(sstring(ch),pos);
}
int sstring::index(const sstring & t, int pos) const    //查找其中的从pos起第一个给定串的位置-KMP算法
{
    if(len == 0)
        return 0;
    int next[t.len];
    get_nextval(t, next);
    int i = pos - 1;
    int j = 0;
    while (i < len && j < t.len) {
        if (j == -1 || str[i] == t.str[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j == t.len)
        return i - j + 1;
    else
        return 0;
}
sstring sstring::operator()(int from, int to)    //切片--相当于substring
{
    int j=0;
    from = max(1,from);
    to = min(len,to);
    char a[to-from+2];
    for(int i=from-1,end=to-1; i<=end; i++)
        a[j++]=str[i];
    a[j]='\0';

    return a;
}
