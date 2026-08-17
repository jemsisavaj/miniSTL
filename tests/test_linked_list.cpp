#include <iostream>
#include "../include/my_linked_list.hpp"

using namespace std;

int main() {
    cout << "==========================================" << endl;
    cout << "      TESTING CUSTOM MY_LINKED_LIST       " << endl;
    cout << "==========================================" << endl;

    MyLinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list.push_front(5);

    cout << "List Elements: ";
    list.print();

    cout << "Size: " << list.size << endl;       
    cout << "Element at 0: " << list.get(0) << endl;
    cout << "Element at 2: " << list.get(2) << endl;

    list.pop_front();
    cout << "After Pop Front: ";
    list.print(); 
    cout << "New Size: " << list.size << endl; 

    return 0;
}