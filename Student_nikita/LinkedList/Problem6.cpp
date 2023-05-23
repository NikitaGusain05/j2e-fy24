#include <unordered_map>
#include <list>
#include <iostream>
#include <vector>
class LRUCache {
private:
    int capacity;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
    std::list<int> lruList;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; // Key does not exist in the cache
        }
        
        // Move the key to the front of the LRU list
        lruList.erase(cache[key].second);
        lruList.push_front(key);
        cache[key].second = lruList.begin();
        
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key exists, update the value and move it to the front of the LRU list
            lruList.erase(cache[key].second);
        }
        else if (cache.size() == capacity) {
            // Cache is full, evict the least recently used key
            int lruKey = lruList.back();
            lruList.pop_back();
            cache.erase(lruKey);
        }
        
        // Add the key-value pair to the cache and the front of the LRU list
        lruList.push_front(key);
        cache[key] = { value, lruList.begin() };
    }
};

int main() {
    std::vector<int> result;
    
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    result.push_back(cache.get(1));
    cache.put(3, 3);
    result.push_back(cache.get(2));
    cache.put(4, 4);
    result.push_back(cache.get(1));
    result.push_back(cache.get(3));
    result.push_back(cache.get(4));
    
    // Print the results
    for (int value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

