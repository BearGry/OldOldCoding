#include <iostream>
#include "Sqlist.h"

using namespace std;

int main() {
    sq_list a;
    Elemtype e;
    Initsqlist(a);
    Sqlistinsert(a,1,5);
    Sqlistinsert(a,1,6);
    Showsqlist(a);
    Sqlistinsert(a,2,3);
    Sqlistinsert(a,5,4);
    Showsqlist(a);

    if(Sqlistempty(a))
        cout<<"wrong"<<endl;
    cout<<Sqlistlength(a)<<endl;
    Getelem(a,2,e);
    cout<<e<<endl;
    Priorelem(a,6,e);
    cout<<e<<endl;
    Nextelem(a,6,e);
    cout<<e<<endl;
    Sqlistdelete(a,0,e);
    Sqlistdelete(a,1,e);
    cout<<e<<endl;
    Showsqlist(a);

    Clearsqlist(a);
    Showsqlist(a);
    Destroysqlist(a);
    Showsqlist(a);


    return 0;
}
