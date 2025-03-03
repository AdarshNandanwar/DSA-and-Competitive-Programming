// https://leetcode.com/problems/lfu-cache/

// Method 1 (HashMap and LinkedList, O(1)):

class LFUCache {
    int capacity;
    int minFreq;
    unordered_map<int, int> keyToVal;
    unordered_map<int, int> keyToFreq;
    unordered_map<int, list<int>> freqToKeys; // List needed for LRU cache tie breaking
    unordered_map<int, list<int>::iterator> keyToItr; // points to the location of the node of the key in list
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 1;
        keyToVal.clear();
        keyToFreq.clear();
        freqToKeys.clear();
        keyToItr.clear();
    }

    void updateAccess(int key){

        int prevFreq = keyToFreq[key];
        int newFreq = prevFreq + 1;

        keyToFreq[key] = newFreq;

        auto prevItr = keyToItr[key];
        freqToKeys[prevFreq].erase(prevItr);
        freqToKeys[newFreq].push_back(key);
        auto newItr = prev(freqToKeys[newFreq].end());
        keyToItr[key] = newItr;

        if(freqToKeys[prevFreq].empty()){
            freqToKeys.erase(prevFreq);

            if(prevFreq == minFreq){
                minFreq++;
            }
        }
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
            // Get least frequently used key
            int keyToRemove = freqToKeys[minFreq].front();

            // Remove key
            keyToVal.erase(keyToRemove);
            keyToFreq.erase(keyToRemove);

            auto prevItr = keyToItr[keyToRemove];
            keyToItr.erase(keyToRemove);
            freqToKeys[minFreq].erase(prevItr);
            
            // minFreq will be set to 1 later as new key will have freq 1
        }

        // Add new key
        keyToVal[key] = value;
        keyToFreq[key] = 1;
        freqToKeys[1].push_back(key);
        auto newItr = prev(freqToKeys[1].end());
        keyToItr[key] = newItr;

        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Alternate Code:

class LFUCache {
public:
    // {key, {value, iterator to position in list}}
    unordered_map<int, pair<int, list<int>::iterator>> val;
    unordered_map<int, int> freq;
    unordered_map<int, list<int>> revFreq;
    int leastFreq, capacity;
    
    LFUCache(int capacity) {
        val.clear();
        freq.clear();
        revFreq.clear();
        leastFreq = 0;  // leastFreq == 0 tells if the capacity given is 0 in the put()
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(val.count(key)){
            // get val
            int res = val[key].first;
            // modify revFreq and increase freq;
            revFreq[freq[key]].erase(val[key].second);
            if(revFreq[freq[key]].empty()) revFreq.erase(freq[key]);
            // update leastFreq if required
            if(leastFreq == freq[key] and !revFreq.count(freq[key])) leastFreq++;
            freq[key]++;
            // modify itr in val
            revFreq[freq[key]].push_back(key);
            val[key].second = prev(revFreq[freq[key]].end());
            return res;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(val.count(key)){
            // modify revFreq and increase freq;
            revFreq[freq[key]].erase(val[key].second);
            // update leastFreq if required
            if(leastFreq == freq[key] and revFreq[freq[key]].empty()) leastFreq++;
            freq[key]++;
            // modify itr in val
            revFreq[freq[key]].push_back(key);
            val[key] = {value, prev(revFreq[freq[key]].end())};
        } else {
            if(capacity == 0){
                if(leastFreq == 0) return;  // initial capacity is 0
                // remove least frequent which is least recent
                auto rem = revFreq[leastFreq].begin();
                int remKey = *rem;
                revFreq[leastFreq].erase(rem);
                if(revFreq[leastFreq].empty()) revFreq.erase(leastFreq);
                freq.erase(remKey);
                val.erase(remKey);
                capacity++;
            }
            // add key and reset leastFreq
            freq[key]++;
            revFreq[1].push_back(key);
            val[key] = {value, prev(revFreq[1].end())};
            leastFreq = 1;
            capacity--;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */