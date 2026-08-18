#include <iostream>
#include <cassert>
#include "../include/my_stack_queue.hpp"

using namespace std;

int main() {
    cout << "==========================================" << endl;
    cout << "      TESTING CUSTOM STACK & QUEUE        " << endl;
    cout << "==========================================" << endl;

    //Stack Test (LIFO)
    MyStack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    assert(s.top() == 30);
    s.pop();
    assert(s.top() == 20);
    assert(s.size() == 2);
    cout << "STACK TESTS PASSED!" << endl;

    //Queue Test (FIFO)
    MyQueue<string> q;
    q.push("first");
    q.push("second");
    q.push("third");

    assert(q.front() == "first");
    q.pop();
    assert(q.front() == "second");
    assert(q.size() == 2);
    cout << "QUEUE TESTS PASSED!" << endl;

    return 0;
}