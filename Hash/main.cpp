#include "hash.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    cout<<"hello world"<<endl;

    Hash<int, string> a;
    cin>>a;
    cout<<a<<endl;
    a[16] = "hello";
    cout<<a[16]<<endl;
    cout<<a<<endl;

//    Hash<int,string> a;
//    int key;
//    string c;
//    for(int i=1; i<=8; i++){
//        cin>>key>>c;
//        a.add(key,c);
//    }
//    if(a.find(5,c))
//       cout<<c<<endl;


    return 0;
}
