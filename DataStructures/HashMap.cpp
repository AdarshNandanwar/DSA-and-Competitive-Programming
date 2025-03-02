// https://leetcode.com/problems/design-hashmap/

// Method 1 (Linked List):

class MyHashMap {
    int size = 10007; // prime number
    vector<list<pair<int, int>>> table;

    int getHash(int key){
        return key % size;
    }

    list<pair<int, int>>::iterator getIterator(int key){
        int hash = getHash(key);
        for(auto it = table[hash].begin(); it != table[hash].end(); it = next(it)){
            if(it->first == key){
                return it;
            }
        }
        return table[hash].end();
    }

public:
    MyHashMap() {
        table = vector<list<pair<int, int>>>(size);
    }
    
    void put(int key, int value) {
        int hash = getHash(key);
        auto it = getIterator(key);
        if(it == table[hash].end()){
            table[hash].push_back(make_pair(key, value));
        } else {
            it->second = value;
        }
    }
    
    int get(int key) {
        int hash = getHash(key);
        auto it = getIterator(key);
        if(it == table[hash].end()){
            return -1;
        }
        return it->second;
    }
    
    void remove(int key) {
        int hash = getHash(key);
        auto it = getIterator(key);
        if(it == table[hash].end()){
            return;
        }
        table[hash].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */