// https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet {
public:
    unordered_map<int, int> index;
    vector<int> v;
    /** Initialize your data structure here. */
    RandomizedSet() {
        index.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(index.find(val) != index.end()){
            return false;
        }
        index[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(index.find(val) == index.end()){
            return false;
        }
        swap(v[index[val]], v[v.size()-1]);
        index[v[index[val]]] = index[val];
        index.erase(val);
        v.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int i = rand()%v.size();
        return v[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */