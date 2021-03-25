// https://leetcode.com/problems/lru-cache/

class LRUCache {
public:
    unordered_map<int, pair<int, list<int>::iterator>> m;
    list<int> l;
    int capacity;
    
    LRUCache(int capacity) {
        m.clear();
        l.clear();
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        } else {
            auto it = m[key].second;
            l.erase(it);
            l.push_front(key);
            m[key].second = l.begin();
            return m[key].first;
        }
    }
    
    void put(int key, int value) {
        if(m.find(key) == m.end()){
            if(capacity == 0){
                m.erase(l.back());
                l.pop_back();
            } else {
                capacity--;
            }
        } else {
            auto it = m[key].second;
            l.erase(it);
        }
        l.push_front(key);
        m[key] = {value, l.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */