// https://www.interviewbit.com/problems/lru-cache/

// Method 1 (Linked List with Hash Map):

#include<bits/stdc++.h>

unordered_map<int, pair<int, list<int>::iterator>> m;
list<int> ll;
int cap = 0;

LRUCache::LRUCache(int capacity) {
    cap = capacity;
    ll.clear();
    m.clear();
}

int LRUCache::get(int key) {
    if(m.count(key)){
        int res = m[key].first;
        ll.erase(m[key].second);
        ll.push_back(key);
        m[key].second = prev(ll.end());
        return res;
    } else {
        return -1;
    }
}

void LRUCache::set(int key, int value) {
    if(m.count(key)){
        m[key].first = value;
        ll.erase(m[key].second);
        ll.push_back(key);
        m[key].second = prev(ll.end());
    } else {
        if(cap == 0){
            int rem_key = ll.front();
            ll.pop_front();
            m.erase(rem_key);
            cap++;
        }
        ll.push_back(key);
        m[key] = make_pair(value, prev(ll.end()));
        cap--;
    }
}
