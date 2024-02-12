#include <iostream>
#include "tree.h"

using namespace std;

void double1(elemtype & a)
{
    a *= 2;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    //实验测试


//    一些测试
//    tree a;
//    cin>>a;
//    cout<<a<<endl;
//    a.add(1);
//    a.add(17);
//    a.add(8);
//    cout<<a<<endl;
//    a.cut(9);
//    cout<<a<<endl;
//
//    tree b = a;
//    b.add(6);
//    cout<<b<<endl;
//    if(b.intree(8))
//        cout<<"I will go!"<<endl;
//    b.traverse(double1);
//    b.clear();
//    cout<<b.len()<<endl;
//    cout<<b<<"hello world!"<<endl;

//    int n = 3;
//    while(n--){
//        tree c;
//        cin>>c;
//        cout<<c<<endl;
//        c.reverse();
//        cout<<c;
//    }

//作业当中的一些测试
    //9-31测试（由于此树即为有序树，所以一定为真的（为假则实现错误），且默认空树也为有序树）;
    //不过算法还是针对所有树进行的有序性判断，思路为中序遍历树有序则为有序树;
//    tree a,b;
//    cin>>a>>b;
//    if(a.inorder() && b.inorder())
//        cout<<"yes"<<endl;


    //9-33测试
//    tree a;
//    cin>>a;
//    for(int i=1; i<=5; i++){
//        int k;
//        cin>>k;
//        a.show_key(k);
//        cout<<endl;
//    }


    //9-38测试
//    tree a,b,c;
//    cin>>a>>b;
//    c = a+b;
//    c.display();

    return 0;
}
