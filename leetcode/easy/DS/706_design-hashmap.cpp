#include "..\..\stdafx.h"
using namespace std;
NS(706)

class MyHashMap {
public:    
    /** Initialize your data structure here. */
    MyHashMap() {
        N = 571;
        buckets.resize(N);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int i = key % N;
        auto it = find_if(buckets[i].begin(), buckets[i].end(), 
            [key](const pair<int, int>& v) {return v.first == key; });
        if (it == buckets[i].end())
            buckets[i].push_back(make_pair(key, value));
        else
            (*it).second = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int i = key % N;
        auto it = find_if(buckets[i].begin(), buckets[i].end(),
            [key](const pair<int, int>& v) {return v.first == key; });
        if (it == buckets[i].end())
            return -1;
        return it->second;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int i = key % N;
        auto it = find_if(buckets[i].begin(), buckets[i].end(),
            [key](const pair<int, int>& v) {return v.first == key; });
        if (it != buckets[i].end())
            buckets[i].erase(it);
    }
private:
    int N;
    vector<list<pair<int, int>>> buckets;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
END_NS