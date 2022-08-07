// https://leetcode.com/problems/design-hashset/

// Method 1 (Hash Table, O(n) time O(1) average time, O(n) space):

class MyHashSet {
    const int prime = 10007;
    vector<list<int>> hashTable;
public:
    
    MyHashSet() {
        hashTable = vector<list<int>>(prime);
    }
    
    void add(int key) {
        int k = key%prime;
        for(auto &val:hashTable[k]){
            if(val == key){
                return;
            }
        }
        hashTable[k].push_back(key);
    }
    
    void remove(int key) {
        int k = key%prime;
        for(auto it=hashTable[k].begin(); it!=hashTable[k].end(); it++){
            if(*it == key){
                hashTable[k].erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int k = key%prime;
        for(auto &val:hashTable[k]){
            if(val == key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

// Method 2 (Cheating, O(1) time, O(n) space):

class MyHashSet {
public:
    /** Initialize your data structure here. */
    
    vector<bool> v;
    
    MyHashSet() {
        v = vector<bool>(1000001);
    }
    
    void add(int key) {
        v[key] = 1;
    }
    
    void remove(int key) {
        v[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return v[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */