// https://www.interviewbit.com/problems/lru-cache/

// Method 1 (Linked List, Hash Map):

#include<bits/stdc++.h>

list<int> order;
// {key, {val, posInList}}
unordered_map<int, pair<int, list<int>::iterator>> m;
int cap;

LRUCache::LRUCache(int capacity) {
    cap = capacity;
    m.clear();
    order.clear();
}

int LRUCache::get(int key) {
    if(!m.count(key)) return -1;
    else {
        auto oldPos = m[key].second;
        order.erase(oldPos);
        order.push_back(key);
        m[key].second = prev(order.end());
        return m[key].first;
    }
}

void LRUCache::set(int key, int value) {
    if(m.count(key)){
        auto oldPos = m[key].second;
        order.erase(oldPos);
        order.push_back(key);
        m[key] = {value, prev(order.end())};
    } else {
        if(cap == 0){
            m.erase(order.front());
            order.pop_front();
            cap++;
        }
        order.push_back(key);
        m[key] = {value, prev(order.end())};
        cap--;
    }
}
