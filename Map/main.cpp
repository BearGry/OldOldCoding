#include "tree.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    tree<int, string> a;
    a[4] = "guoshun";
    a[2] = "lzz";
    a[7] = "jn";
    a[-1] = "yue";
    a[6] = "park";
    a[5] = "cl";

    cout<<a[-1]<<endl;


    return 0;
}
