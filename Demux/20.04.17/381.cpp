// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/

// Method 1 (O(1)):

class RandomizedCollection {
public:
    
    unordered_map<int, vector<int>> ind;
    vector<pair<int, int>> v;
    
    /** Initialize your data structure here. */
    RandomizedCollection() {
        ind.clear();
        v.clear();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool ret = true;
        if(ind[val].size())
            ret = false;
        ind[val].push_back(v.size());
        v.push_back({val, ind[val].size()-1});
        return ret;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(ind[val].size() == 0){
            return false;
        }
        
        int pos = ind[val][ind[val].size()-1];
        swap(v[pos], v[v.size()-1]);
        int indPos = v[pos].second;
        ind[v[pos].first][indPos] = pos;
        ind[val].pop_back();
        v.pop_back();
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int i = rand()%v.size();
        return v[i].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

// Method 2 (O(logn)):

class RandomizedCollection {
public:
    
    unordered_map<int, set<int>> ind;
    vector<int> v;
    
    /** Initialize your data structure here. */
    RandomizedCollection() {
        ind.clear();
        v.clear();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool ret = true;
        if(ind[val].size())
            ret = false;
        ind[val].insert(v.size());
        v.push_back(val);
        return ret;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(ind[val].size() == 0){
            return false;
        }
        int index = *ind[val].begin();
        swap(v[index], v[v.size()-1]);
        ind[v[index]].erase(v.size()-1);
        if(v[index] != v[v.size()-1]){
            ind[val].erase(index);
            ind[v[index]].insert(index);
        }
        v.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int i = rand()%v.size();
        return v[i];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */