#include <iostream>
#include "SeqList.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    SeqList a;
    a.add(1);
    a.add(6);
    a.add(4);
    a.add(3);
    a.add(14);
    a.add(6);

    SeqList b;
    b.add(6);
    b.add(7);
    b.add(4);
    b.add(8);
    b.add(11);
    b.add(3);
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<(a^b)<<endl;
    SeqList c = a+b;
    cout<<c<<endl;

    cout<<a<<endl;
    a.add_sq(5);
    cout<<a<<endl;


    if(5>=a[a.len()-1])
        a.add(5);
    else{
        for(int i=0; i<a.len(); i++)
            if(5<=a[i]){
                a.insert(i+1,5);
                break;
            }
    }
    cout<<a<<endl;

    return 0;
}
