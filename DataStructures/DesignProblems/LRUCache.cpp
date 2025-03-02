// https://leetcode.com/problems/lru-cache/

// Method 1 (Hash Map + Linked List, O(1)):

class LRUCache {
    int capacity;
    unordered_map<int, int> keyToVal;
    list<int> keysInAccessOrder;
    unordered_map<int, list<int>::iterator> keyToItr; // points to the node in the list keysInAccessOrder
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        keyToVal.clear();
        keyToItr.clear();
        keysInAccessOrder.clear();
    }

    void updateAccess(int key) {
        auto prevItr = keyToItr[key];

        keysInAccessOrder.erase(prevItr);
        keysInAccessOrder.push_back(key);
        auto newItr = prev(keysInAccessOrder.end());

        keyToItr[key] = newItr;
    }
    
    int get(int key) {
        if(keyToVal.count(key) == 0){
            return -1;
        }

        updateAccess(key);

        return keyToVal[key];
    }
    
    void put(int key, int value) {
        if(keyToVal.count(key) > 0){

            keyToVal[key] = value;
            updateAccess(key);

            return;
        }

        if(keyToVal.size() == capacity){
            // Get the oldest key
            int keyToRemove = keysInAccessOrder.front();

            // Remove key
            keyToVal.erase(keyToRemove);
            keysInAccessOrder.pop_front();
            keyToItr.erase(keyToRemove);
        }

        // Insert new key
        keyToVal[key] = value;
        keysInAccessOrder.push_back(key);
        auto newItr = prev(keysInAccessOrder.end());
        keyToItr[key] = newItr;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Alternate Code:

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