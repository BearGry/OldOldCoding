#include <iostream>
#include "list2.h"

using namespace std;

int main() {
    List a;
    List_init(a);
    List_add(a,1);
    List_add(a,2);
    List_add(a,3);
    List_add(a,4);
    List_add(a,3);

    List_print(a);
    turn_over(a);
    List_print(a);

    List_clear(a);

    return 0;
}
