#include <iostream>
#include "Que.h"

using namespace std;

int main() {
//    std::cout << "Hello, World!" << std::endl;
    Queue queue;
    Elemtype elem;
    Init_Queue(queue);
    Enqueue(queue,1);
    Dequeue(queue,elem);
    cout<<elem<<endl;
    Enqueue(queue,2);
    Enqueue(queue,2);
    Enqueue(queue,3);
    for(int i=0;i<4;i++){
        Dequeue(queue,elem);
        cout<<elem<<endl;
    }

    free(queue.rear);

    return 0;
}
