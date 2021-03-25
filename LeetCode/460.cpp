// https://leetcode.com/problems/lfu-cache/

// Method 1 (HashMap and LinkedList, O(1)):
// Can be speed up by combining val and freq HashMap

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