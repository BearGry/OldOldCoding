#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    Stack a;
    Stack_init(a);
    Date e;
    e=1;
    Stack_push(a,e);
    e=2;
    Stack_push(a,e);
    e=3;
    Stack_push(a,e);
    e=4;
    Stack_push(a,e);

    if(!Stack_empty(a))
        cout<<"It is not empty"<<endl;
    Stack_gettop(a,e);
    cout<<e<<endl;
    Stack_pop(a,e);
    Stack_pop(a,e);
    cout<<e<<endl;

    cout<<Stack_length(a)<<endl;
    Stack_destroy(a);

    Stack_destroy(a);

    return 0;
}
