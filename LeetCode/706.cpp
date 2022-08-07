// https://leetcode.com/problems/design-hashmap/

// Method 1 (Linked List to handle collisions O(1e6/1009)):

class MyHashMap {
    const int prime = 10007;
    vector<list<pair<int, int>>> hashTable;
public:
    MyHashMap() {
        hashTable = vector<list<pair<int, int>>>(prime);
    }
    
    int getIndex(int key){
        return key % prime;
    }
    
    void put(int key, int value) {
        int index = getIndex(key);
        auto it = hashTable[index].begin();
        while(it != hashTable[index].end()){
            if(it->first == key){
                it->second = value;
                return;
            }
            it++;
        }
        hashTable[index].push_back(make_pair(key, value));
    }
    
    int get(int key) {
        int index = getIndex(key);
        auto it = hashTable[index].begin();
        while(it != hashTable[index].end()){
            if(it->first == key){
                return it->second;
            }
            it++;
        }
        return -1;
    }
    
    void remove(int key) {
        int index = getIndex(key);
        auto it = hashTable[index].begin();
        while(it != hashTable[index].end()){
            if(it->first == key){
                hashTable[index].erase(it);
                return;
            }
            it++;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

// Alternate Code:

class MyHashMap {
public:
    // {key, val}
    vector<list<pair<int, int>>> data;
    int prime;
    
    MyHashMap() {
        prime = 1009;
        data = vector<list<pair<int, int>>>(prime, list<pair<int, int>>(0));
    }
    
    int hash(int x){
        return x%prime;
    }
    
    void put(int key, int value) {
        int index = hash(key);
        for(auto &i:data[index]){
            if(i.first == key){
                i.second = value;
                return;
            }
        }
        data[index].push_back(make_pair(key, value));
    }
    
    int get(int key) {
        int index = hash(key);
        for(auto &i:data[index]){
            if(i.first == key){
                return i.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int index = hash(key);
        auto it=data[index].begin();
        for(; it!=data[index].end(); it++){
            if(it->first == key){
                break;
            }
        }
        if(it != data[index].end()) data[index].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

// Method 2 (Naive vector, O(1e6)):

class MyHashMap {
public:
    vector<int> data;
    
    MyHashMap() {
        this->data = vector<int>(1+1e6, INT_MIN);
    }
    
    void put(int key, int value) {
        data[key] = value;
    }
    
    int get(int key) {
        return data[key]==INT_MIN ? -1 : data[key];
    }
    
    void remove(int key) {
        data[key] = INT_MIN;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */