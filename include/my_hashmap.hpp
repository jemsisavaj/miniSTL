#ifndef MY_HASHMAP_HPP
#define MY_HASHMAP_HPP

#include <iostream>
#include <string>

template <typename K, typename V>
struct HashNode {
    K key;
    V value;
    HashNode* next;

    HashNode(K k, V v) : key(k), value(v), next(nullptr) {}
};

template <typename K, typename V>
class MyHashMap {
private:
    HashNode<K, V>** buckets;
    int capacity;
    int current_size;

    //Hash Function
    int getHashIndex(const std::string& key) {
        unsigned long hash = 0;
        for (char ch : key) {
            hash = (hash * 31) + ch;
        }
        return hash % capacity;
    }

    int getHashIndex(int key) {
        return (key >= 0 ? key : -key) % capacity;
    }

public:
    MyHashMap(int cap = 16) {
        capacity = cap;
        current_size = 0;
        buckets = new HashNode<K, V>*[capacity];
        for (int i = 0; i < capacity; i++) {
            buckets[i] = nullptr;
        }
    }

    ~MyHashMap() {
        for (int i = 0; i < capacity; i++) {
            HashNode<K, V>* curr = buckets[i];
            while (curr != nullptr) {
                HashNode<K, V>* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        delete[] buckets;
    }

    //Add and update Key-Value 
    void put(K key, V value) {
        if ((float)current_size / capacity >= 0.75) {
            rehash();
        }
        int index = getHashIndex(key);
        HashNode<K, V>* curr = buckets[index];

        while (curr != nullptr) {
            if (curr->key == key) {
                curr->value = value;
                return;
            }
            curr = curr->next;
        }

        //Separate Chaining
        HashNode<K, V>* newNode = new HashNode<K, V>(key, value);
        newNode->next = buckets[index];
        buckets[index] = newNode;
        current_size++;
    }

    //Key->Value
    V get(K key) {
        int index = getHashIndex(key);
        HashNode<K, V>* curr = buckets[index];

        while (curr != nullptr) {
            if (curr->key == key) {
                return curr->value;
            }
            curr = curr->next;
        }
        return V();
    }

    //delete
    bool remove(K key) {
        int index = getHashIndex(key);
        HashNode<K, V>* curr = buckets[index];
        HashNode<K, V>* prev = nullptr;

        while (curr != nullptr) {
            if (curr->key == key) {
                if (prev == nullptr) {
                    buckets[index] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                current_size--;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    int size() const {
        return current_size;
    }

    bool empty() const {
        return current_size == 0;
    }

    //rehash
    void rehash() {
        int oldCapacity = capacity;
        capacity *= 2;
        HashNode<K, V>** oldBuckets = buckets;

        buckets = new HashNode<K, V>*[capacity];
        for (int i = 0; i < capacity; i++) {
            buckets[i] = nullptr;
        }

        current_size = 0;
        for (int i = 0; i < oldCapacity; i++) {
            HashNode<K, V>* curr = oldBuckets[i];
            while (curr != nullptr) {
                put(curr->key, curr->value); 
                HashNode<K, V>* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        delete[] oldBuckets;
    }
};

#endif