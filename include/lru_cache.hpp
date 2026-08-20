#ifndef LRU_CACHE_HPP
#define LRU_CACHE_HPP

#include <iostream>
#include <unordered_map>

template <typename K, typename V>
struct DNode {
    K key;
    V value;
    DNode* prev;
    DNode* next;

    DNode(K k, V v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

template <typename K, typename V>
class LRUCache {
private:
    int capacity;
    std::unordered_map<K, DNode<K, V>*> cacheMap;
    DNode<K, V>* head; // Dummy Head 
    DNode<K, V>* tail; // Dummy Tail 

    void removeNode(DNode<K, V>* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(DNode<K, V>* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void moveToHead(DNode<K, V>* node) {
        removeNode(node);
        addToHead(node);
    }

    DNode<K, V>* popTail() {
        DNode<K, V>* res = tail->prev;
        removeNode(res);
        return res;
    }

public:
    LRUCache(int cap) : capacity(cap) {
        head = new DNode<K, V>(K(), V());
        tail = new DNode<K, V>(K(), V());
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        DNode<K, V>* curr = head;
        while (curr != nullptr) {
            DNode<K, V>* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    // ૧. ડેટા મેળવવો (O(1))
    V get(K key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return V(); // કી ન મળે તો ડિફોલ્ટ વેલ્યુ
        }
        DNode<K, V>* node = cacheMap[key];
        moveToHead(node);
        return node->value;
    }

    void put(K key, V value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            DNode<K, V>* node = cacheMap[key];
            node->value = value;
            moveToHead(node);
        } else {
            DNode<K, V>* newNode = new DNode<K, V>(key, value);
            cacheMap[key] = newNode;
            addToHead(newNode);

            if ((int)cacheMap.size() > capacity) {
                DNode<K, V>* tailNode = popTail();
                cacheMap.erase(tailNode->key);
                delete tailNode;
            }
        }
    }

    int size() const {
        return cacheMap.size();
    }
};

#endif