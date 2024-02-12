#include <iostream>
#include "vector.h"

using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<int> a;
    vector<double> b;

    for(int i=1; i<=5; i++){
        a.push(2*i);
        b.push(2*i+1);
    }
    if(a.empty())
        cout<<"error"<<endl;
    for(int i=0; i<a.length(); i++){
        cout<<a[i]<<"\t"<<b[i]<<endl;
    }
    a[2] = 0;
    cout<<a[2]<<endl;

    vector<int> c = a;
    for(int i=0; i<c.length(); i++)
        cout<<c[i]<<" ";
    vector<int> d(4);
    d = a;
    cout<<endl;
    for(int i=0; i<d.length(); i++)
        cout<<d[i]<<" ";

    return 0;
}
