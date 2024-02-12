#include <iostream>
#include "String.h"

using namespace std;

int main() {
    String s,a,b;
    InitString(s);
    InitString(a);
    InitString(b);

    StrAssign(s,"ab ac bc ac bc ad");
    StrAssign(a,"ac");
    StrAssign(b,"bcde");

    StrReplace(s,a,b);
//    StrClear(s,a);
//    Concat(s,a,b);
//    SubString(a,s,1,3);
    cout<<s<<endl;
//    cout<<a<<endl;

//    cout<<Compare(s,a);

    Strdestory(s);
    Strdestory(a);
    Strdestory(b);

    return 0;
}
