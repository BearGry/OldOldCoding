#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue a;
    Date e;
    Queue_init(a);
    Queue_enqueue(a,1);
    Queue_enqueue(a,2);
    Queue_enqueue(a,3);
    Queue_enqueue(a,4);
    Queue_gethead(a,e);
    cout<<e<<endl;

    Queue_dequeue(a,e);
    cout<<e<<endl;
    Queue_dequeue(a,e);
    cout<<e<<endl;
    Queue_dequeue(a,e);
    cout<<e<<endl;
    Queue_dequeue(a,e);
    cout<<e<<endl;
    Queue_dequeue(a,e);
    cout<<e<<endl;
    cout<<Queue_length(a)<<endl;

    if(Queue_destroy(a))
        cout<<"Destroy right."<<endl;

    return 0;
}
