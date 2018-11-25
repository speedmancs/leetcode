#include "..\..\stdafx.h"
using namespace std;
NS(705)
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        N = 507;
        buckets.resize(N);
    }

    void add(int key) {
        int index;
        auto it = lookup(key, index);
        if (it == buckets[index].end())
            buckets[index].push_back(key);
    }

    void remove(int key) {
        int index;
        auto it = lookup(key, index);
        if (it != buckets[index].end())
            buckets[index].erase(it);
    }

    list<int>::iterator lookup(int key, int& index)
    {
        index = key % N;
        return find(buckets[index].begin(), buckets[index].end(), key);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int index;
        auto it = lookup(key, index);
        return it != buckets[index].end();
    }

    int N;
    vector<list<int>> buckets;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
END_NS