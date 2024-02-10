#include <iostream>
#include "Node.h"
using namespace std;

int main() {
    Node<int> a(10);
    a += 5;
    a += 143;
    a += 2332;

    cout << a.minValue();
    return 0;
}
