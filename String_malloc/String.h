//
// Created by xiaodian& on 2022/10/26.
//

#ifndef STRING_MALLOC_STRING_H
#define STRING_MALLOC_STRING_H
#include "iostream"

using namespace std;

typedef struct {
    char * data;
    int length;
}String;

void InitString(String &);
bool StrAssign(String &, char * a);
bool StrAssign(String &, String);
int Strlen(String);
void Strdestory(String &);
bool StrClear(String &, String);
bool StrAdd(String &, int, String);
bool Concat(String &, String, String);
bool SubString(String &, String, int, int);
int  Index(String, String, int pos = 1);
int  Compare(const String, const String);
bool StrReplace(String &, String, String);
ostream & operator<<(ostream &,const String);


#endif //STRING_MALLOC_STRING_H
