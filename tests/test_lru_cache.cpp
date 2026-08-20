#include <iostream>
#include <cassert>
#include <string>
#include "../include/lru_cache.hpp"

using namespace std;

int main() {
    cout << "==========================================" << endl;
    cout << "       TESTING CUSTOM LRU_CACHE           " << endl;
    cout << "==========================================" << endl;

    // કેપેસિટી = ૨ વાળી કેશ બનાવી
    LRUCache<int, string> lru(2);

    lru.put(1, "one");
    lru.put(2, "two");

    assert(lru.get(1) == "one"); 
    lru.put(3, "three");

    assert(lru.get(2) == "");    
    assert(lru.get(3) == "three"); 
    assert(lru.get(1) == "one");   

    lru.put(1, "ONE_UPDATED");
    assert(lru.get(1) == "ONE_UPDATED");

    cout << "ALL LRU CACHE TESTS PASSED SUCCESSFULLY!" << endl;
    return 0;
}