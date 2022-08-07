// https://leetcode.com/problems/lru-cache/

// Method 1 (Hash Map + Linked List, O(1)):

class LRUCache {
public:
    int capacity;
    list<int> accessOrder;
    unordered_map<int, int> data;
    unordered_map<int, list<int>::iterator> listPointer;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        data.clear();
        accessOrder.clear();
    }
    
    int get(int key) {
        if(data.count(key)){
            auto ptr = listPointer[key];
            accessOrder.erase(ptr);
            accessOrder.push_front(key);
            listPointer[key] = accessOrder.begin();
            return data[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(!data.count(key)){
            if(capacity == 0){
                int lastKey = *prev(accessOrder.end());
                data.erase(lastKey);
                listPointer.erase(lastKey);
                accessOrder.pop_back();
                capacity++;                
            }
        } else {
            auto ptr = listPointer[key];
            accessOrder.erase(ptr);
            capacity++;   
        }
        accessOrder.push_front(key);
        listPointer[key] = accessOrder.begin();
        data[key] = value;
        capacity--;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */