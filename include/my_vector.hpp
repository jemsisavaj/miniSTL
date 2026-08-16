#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

#include <iostream>

template <typename T>
class MyVector {
public:
    T* arr;
    int size;
    int capacity;

    MyVector(){
        capacity = 1;
        size = 0;
        arr = new T[1];
    }

    void push_back(T val){
        if(size == capacity){
            capacity *= 2;
            T* temp = new T[capacity];

            for(int i=0; i<size; i++){
                temp[i] = arr[i];
            }

            delete[] arr;
            arr = temp;
        }
        arr[size] = val;
        size++;
    }

    void pop_back(){
        if(size > 0){
            size--;
        }
    }

    T get(int index){
        return arr[index];
    }
};

#endif
