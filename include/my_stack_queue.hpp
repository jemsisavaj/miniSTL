#ifndef MY_STACK_QUEUE_HPP
#define MY_STACK_QUEUE_HPP

#include <iostream>
#include "my_vector.hpp"
#include "my_linked_list.hpp"

// Stack-LIFO
template <typename T>
class MyStack {
private:
    MyVector<T> vec;

public:
    void push(T val) {
        vec.push_back(val);
    }

    void pop() {
        vec.pop_back();
    }

    T top() {
        if (vec.size == 0) return T();
        return vec.get(vec.size - 1);
    }

    bool empty() const {
        return vec.size == 0;
    }

    int size() const {
        return vec.size;
    }
};

// Queue-FIFO
template <typename T>
class MyQueue {
private:
    MyLinkedList<T> list;

public:
    void push(T val) {
        list.push_back(val);
    }

    void pop() {
        list.pop_front();
    }

    T front() {
        if (list.empty() || list.head == nullptr) return T();
        return list.head->data; 
    }

    bool empty() const {
        return list.empty();
    }

    int size() const {
        return list.size;
    }
};

#endif