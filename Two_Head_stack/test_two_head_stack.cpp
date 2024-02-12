#include <iostream>
#include "Stacks.h"

using namespace std;

int main()
{
    Stack stack;
    Init_Stack(stack);
    ElemType elem;
    pop(stack,0,elem);
    for(int i=1;i<=11;i++){
        push(stack,0,i);
    }
    pop(stack,1,elem);
    for(int i=1;i<=12;i++){
        pop(stack,0,elem);
        cout<<elem<<endl;
    }
    for(int i=1;i<=14;i++){
        push(stack,1,i);
    }
    for(int i=1; i<=17;i++){
        pop(stack,1,elem);
        cout<<elem<<endl;
    }

    free(stack.base);
}
