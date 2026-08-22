#include <iostream>
#include <cassert>
#include <string>

#include "../include/my_vector.hpp"
#include "../include/my_linked_list.hpp"
#include "../include/my_stack_queue.hpp"
#include "../include/my_hashmap.hpp"
#include "../include/lru_cache.hpp"

using namespace std;

void testVector() {
    cout << "[TEST 1/5] Testing MyVector...";
    MyVector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    assert(v.size == 3);
    assert(v.get(0) == 10);
    v.pop_back();
    assert(v.size == 2);
    cout << " -> PASSED!" << endl;
}

void testLinkedList() {
    cout << "[TEST 2/5] Testing MyLinkedList...";
    MyLinkedList<int> list;
    list.push_back(20);
    list.push_front(10);
    assert(list.get(0) == 10);
    assert(list.get(1) == 20);
    list.pop_front();
    assert(list.get(0) == 20);
    cout << " -> PASSED!" << endl;
}

void testStackQueue() {
    cout << "[TEST 3/5] Testing MyStack & MyQueue...";
    MyStack<int> s;
    s.push(100);
    s.push(200);
    assert(s.top() == 200);
    s.pop();
    assert(s.top() == 100);

    MyQueue<string> q;
    q.push("first");
    q.push("second");
    assert(q.front() == "first");
    q.pop();
    assert(q.front() == "second");
    cout << " -> PASSED!" << endl;
}

void testHashMap() {
    cout << "[TEST 4/5] Testing MyHashMap...";
    MyHashMap<string, int> map;
    map.put("apple", 50);
    map.put("banana", 30);
    assert(map.get("apple") == 50);
    map.put("apple", 60);
    assert(map.get("apple") == 60);
    assert(map.remove("banana") == true);
    assert(map.get("banana") == 0);
    cout << " -> PASSED!" << endl;
}

void testLRUCache() {
    cout << "[TEST 5/5] Testing LRUCache...";
    LRUCache<int, string> lru(2);
    lru.put(1, "A");
    lru.put(2, "B");
    assert(lru.get(1) == "A");
    lru.put(3, "C"); // 2 will be evicted
    assert(lru.get(2) == "");
    assert(lru.get(3) == "C");
    cout << " -> PASSED!" << endl;
}

int main() {
    cout << "==========================================" << endl;
    cout << "    RUNNING ALL MINI-STL SYSTEM TESTS     " << endl;
    cout << "==========================================" << endl;

    testVector();
    testLinkedList();
    testStackQueue();
    testHashMap();
    testLRUCache();

    cout << "==========================================" << endl;
    cout << "  ALL DATA STRUCTURE TESTS PASSED! (5/5)  " << endl;
    cout << "==========================================" << endl;

    return 0;
}