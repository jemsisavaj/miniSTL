#include <iostream>
#include "../include/my_vector.hpp"

using namespace std;

int main() {
    MyVector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << "Size: " << v.size << endl;         // 3
    cout << "Capacity: " << v.capacity << endl; // 4

    cout << "Element at 0: " << v.get(0) << endl; // 10
    cout << "Element at 1: " << v.get(1) << endl; // 20

    v.pop_back();
    cout << "After pop, Size: " << v.size << endl; // 2

    return 0;
}