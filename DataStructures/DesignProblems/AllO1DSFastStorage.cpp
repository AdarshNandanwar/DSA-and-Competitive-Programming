// https://leetcode.com/problems/all-oone-data-structure/

// Method 1 (Linked List, O(1) time):

// https://leetcode.com/problems/all-oone-data-structure/

class AllOne {
    unordered_map<string, int> keyToFreq;
    unordered_map<int, unordered_set<string>> freqToKeys; // Order does't matter as we can return any string in case of tie. So, we can use unordered_set instead of list
    list<int> freqInOrder; // list of frequencies that exist in the data structure in ascending order
    unordered_map<int, list<int>::iterator> freqToItr; // pointer to the position of the freq in the list freqInOrder

public:
    /** Initialize your data structure here. */
    AllOne() {
        keyToFreq.clear();
        freqToKeys.clear();
        freqInOrder.clear();
        freqToItr.clear();
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(keyToFreq.count(key) == 0){
            // Insert new key

            keyToFreq[key] = 1;
            freqToKeys[1].insert(key);
            if(freqToItr.count(1) == 0){
                freqInOrder.push_front(1);
                freqToItr[1] = freqInOrder.begin();
            }

        } else {
            // Increase freq

            int prevFreq = keyToFreq[key];
            keyToFreq.erase(key);
            freqToKeys[prevFreq].erase(key);
            auto posToInsertNextFreq = next(freqToItr[prevFreq]);
            if(freqToKeys[prevFreq].size() == 0){
                auto prevFreqItr = freqToItr[prevFreq];
                freqInOrder.erase(prevFreqItr);
                freqToItr.erase(prevFreq);
                freqToKeys.erase(prevFreq);
            }

            int newFreq = prevFreq + 1;
            keyToFreq[key] = newFreq;
            freqToKeys[newFreq].insert(key);
            if(freqToItr.count(newFreq) == 0){
                freqInOrder.insert(posToInsertNextFreq, newFreq);
                auto newItr = prev(posToInsertNextFreq);
                freqToItr[newFreq] = newItr;
            }
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(keyToFreq.count(key) == 0){
            return;
        }
    
        int prevFreq = keyToFreq[key];
        keyToFreq.erase(key);
        freqToKeys[prevFreq].erase(key);
        auto posToInsertNextFreq = freqToItr[prevFreq];
        if(freqToKeys[prevFreq].size() == 0){
            auto prevFreqItr = freqToItr[prevFreq];
            posToInsertNextFreq = next(posToInsertNextFreq);
            freqInOrder.erase(prevFreqItr);
            freqToItr.erase(prevFreq);
            freqToKeys.erase(prevFreq);
        }

        if(prevFreq == 1){
            return;
        }

        int newFreq = prevFreq - 1;
        keyToFreq[key] = newFreq;
        freqToKeys[newFreq].insert(key);
        if(freqToItr.count(newFreq) == 0){
            freqInOrder.insert(posToInsertNextFreq, newFreq);
            auto newItr = prev(posToInsertNextFreq);
            freqToItr[newFreq] = newItr;
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(keyToFreq.size() == 0){
            return "";
        }

        int maxFreq = freqInOrder.back();
        return *freqToKeys[maxFreq].begin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(keyToFreq.size() == 0){
            return "";
        }

        int minFreq = freqInOrder.front();
        return *freqToKeys[minFreq].begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
