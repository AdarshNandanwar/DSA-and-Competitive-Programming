// https://leetcode.com/problems/insert-delete-getrandom-o1/

// Method 1 (vector, hash map, O(1) time):

class RandomizedSet {
public:
    
    unordered_map<int, int> index;
    vector<int> v;
    
    RandomizedSet() {
        index.clear();
        v.clear();
    }
    
    bool insert(int val) {
        if(index.count(val)) return false;
        v.push_back(val);
        index[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!index.count(val)) return false;
        swap(v[index[val]], v[v.size()-1]);
        index[v[index[val]]] = index[val];
        index.erase(val);
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

// Method 2 (list, hash map, O(n) time for random):

class RandomizedSet {
public:
    
    unordered_map<int, list<int>::iterator> m;
    list<int> l;
    
    RandomizedSet() {
        l.clear();
        m.clear();
    }
    
    bool insert(int val) {
        if(m.count(val)) return false;
        l.push_back(val);
        m[val] = prev(l.end());
        return true;
    }
    
    bool remove(int val) {
        if(!m.count(val)) return false;
        l.erase(m[val]);
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        return *next(l.begin(), rand()%l.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */