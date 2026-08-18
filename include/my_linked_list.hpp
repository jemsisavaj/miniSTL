#ifndef MY_LINKED_LIST_HPP
#define MY_LINKED_LIST_HPP

#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class MyLinkedList {
public:
    Node<T>* head;
    Node<T>* tail;
    int size;

    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void push_front(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void push_back(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode; 
            tail = newNode;    
        }
        size++;
    }

    void pop_front() {
        if (head == nullptr) return;

        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;

        if (head == nullptr) {
            tail = nullptr;
        }
    }

    T get(int index) {
        if (index < 0 || index >= size || head == nullptr) {
            return T();
        }

        Node<T>* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->data;
    }

    bool empty() const {
        return size == 0;
    }
};

#endif