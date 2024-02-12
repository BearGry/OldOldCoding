//
// Created by xiaodian& on 2022/10/26.
//

#include "iostream"
#include "String.h"

using namespace std;

static int how_long(char *);
static void get_nextval(String, int next[]);
static void StrCut(String &, int, int);

void InitString(String &string) {
    string.data = NULL;
    string.length = 0;
}

////将string赋值为字符串a，即使a是空串；
////ATTENTION：如果复制失败即堆分配失败，原来串不应该被修改；
bool StrAssign(String &string, char *a) {
    int len = how_long(a);
    if (len) {
        char *ch = (char *) malloc(len * sizeof(char));
        if (ch == NULL) {
            cout << "Assign error in malloc. Maybe there is no memory." << endl;
            return false;
        } else {
            if (string.data != NULL)
                free(string.data);
            string.data = ch;
            for (int i = 0; i < len; i++)
                string.data[i] = a[i];
            string.length = len;
            return true;
        }
    } else {
        if (string.data != NULL)
            free(string.data);
        string.data = NULL;
        string.length = 0;
    }
    return true;
}

bool StrAssign(String & s, String t)
{
    return StrAssign(s,t.data);
}

int Strlen(String string) {
    return string.length;
}

void Strdestory(String &string) {
    if (string.data == NULL)
        return;
    free(string.data);
    InitString(string);
}

bool StrClear(String & s, String t)
{
    String a;
    a.data = NULL;
    a.length = 0;
    return StrReplace(s,t,a);
}

////将a,b连接在一起赋给string，失败不修改；
////暂不考虑a，b是空串；
bool Concat(String &string, String a, String b) {
    int len = a.length + b.length;
    char *ch = (char *) malloc(len * sizeof(char));
    if (ch == NULL) {
        cout << "Concat error in malloc. So concat error." << endl;
        return false;
    }
    Strdestory(string);
    string.length = len;
    string.data = ch;
    int i;
    for (i = 0; i < a.length; i++)
        string.data[i] = a.data[i];
    for (int j = 0; j < b.length; j++)
        string.data[i++] = b.data[j];

    return true;
}

bool SubString(String &string, String a, int pos, int len) {
    if (pos < 1 || pos > a.length || len < 0 || pos + len - 1 > a.length) {
        cout << "pos or len error OR a is empty. SubString false." << endl;
        return false;
    }
    if (len == 0) {
        Strdestory(string);
        InitString(string);
        return true;
    }
    char *ch = (char *) malloc(len * sizeof(char));
    if (ch == NULL) {
        cout << "There is not enough memory. So SubString error." << endl;
        return false;
    }
    Strdestory(string);
    string.data = ch;
    string.length = len;
    for (int j = pos - 1, end = pos - 1 + len, i = 0; j < end; j++)
        string.data[i++] = a.data[j];

    return true;
}

////从pos（默认值为0）处开始查询t在s中第一次出现的位置，返回序号，不存在则返回0；
int Index(String s, String t, int pos) {
    if(s.length == 0)
        return 0;
    int next[t.length];
    get_nextval(t, next);
    int i = pos - 1;
    int j = 0;
    while (i < s.length && j < t.length) {
        if (j == -1 || s.data[i] == t.data[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j == t.length)
        return i - j + 1;
    else
        return 0;
}

int  Compare(const String s, const String t)
{
    int i=0,j=0;
    int s_len=s.length,t_len=t.length;
    while(i<s_len && j<t_len){
        if(s.data[i] > t.data[j])
            return 1;
        else if(s.data[i] < t.data[j])
            return -1;
        else{
            i++; j++;
        }
    }
    if(s_len == t_len)
        return 0;
    else if(s_len < t_len)
        return -1;
    else
        return 1;
}

bool StrAdd(String & s, int pos, String t)
{
    if(pos<1 || pos > s.length+1)
        return false;
    if(s.length == 0){
        StrAssign(s,t.data);
        return true;
    }
    char * ch = (char *) realloc(s.data,(s.length+t.length)*sizeof (char));
    if(ch == NULL){
        cout<<"There is no memory to add. So StrAdd Error."<<endl;
        return false;
    }
    s.data = ch;
    for(int i=s.length-1,end=pos-1,len=t.length; i>=end; i--)
        s.data[i+len] = s.data[i];
    for(int i=pos-1,end=pos-1+t.length,j=0; i<end; i++)
        s.data[i] = t.data[j++];
    s.length += t.length;

    return true;
}

bool StrReplace(String & s, String a, String b)
{
    int pos = 1;
    pos = Index(s, a, pos);
    while (pos){
        StrCut(s,pos,a.length);
        if(StrAdd(s,pos,b) == false)
            return false;
        pos = Index(s,a,pos+b.length);
    }
    return true;
}

ostream & operator<<(ostream & cout, const String s)
{
    cout<<"\"";
    for(int i=0,end=s.length; i<end; i++)
        cout<<s.data[i];
    cout<<"\"";
    return cout;
}

static int how_long(char *a) {
    int len = 0;
    int i = 0;
    while (a[i++] != '\0')
        ++len;
    return len;
}

static void get_nextval(String t, int next[]) {
    next[0] = -1;
    int i = 0;
    int j = -1;
    int end = t.length - 1;
    while (i < end) {
        if (j == -1 || t.data[i] == t.data[j]) {
            i++;
            j++;
            if (t.data[i] == t.data[j]) next[i] = next[j];
            else next[i] = j;
        } else
            j = next[j];
    }
}

static void StrCut(String & s, int pos, int len)
{
    int begin = pos-1+len;
    int end = s.length;
    for(int i=begin; i<end; i++)
        s.data[i-len] = s.data[i];
    s.length -= len;
    char * ch = (char *)malloc(s.length*sizeof (char));
    for(int i=0; i<s.length; i++)
        ch[i] = s.data[i];
    free(s.data);
    s.data = ch;
}



































