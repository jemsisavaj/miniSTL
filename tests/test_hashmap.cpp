#include <iostream>
#include <cassert>
#include <string>
#include "../include/my_hashmap.hpp"

using namespace std;

int main() {
    cout << "==========================================" << endl;
    cout << "       TESTING CUSTOM MY_HASHMAP          " << endl;
    cout << "==========================================" << endl;

    MyHashMap<string, int> map;

    //Put & Get Test
    map.put("apple", 100);
    map.put("banana", 200);
    map.put("cherry", 300);

    assert(map.get("apple") == 100);
    assert(map.get("banana") == 200);
    assert(map.get("cherry") == 300);
    assert(map.size() == 3);

    //Update Existing Key Test
    map.put("apple", 150);
    assert(map.get("apple") == 150);
    assert(map.size() == 3);

    //Remove Test
    assert(map.remove("banana") == true);
    assert(map.get("banana") == 0); 
    assert(map.size() == 2);

    //Non-existing key remove
    assert(map.remove("mango") == false);

    cout << "ALL HASHMAP TESTS PASSED SUCCESSFULLY!" << endl;
    return 0;
}