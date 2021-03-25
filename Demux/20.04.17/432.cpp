// https://leetcode.com/problems/all-oone-data-structure/

// https://leetcode.com/problems/all-oone-data-structure/

class AllOne {
public:
    
    // <freq, itr to pos in revFreq list>
    unordered_map<string, pair<int, list<string>::iterator>> freq;
    unordered_map<int, list<string>> revFreq;
    unordered_map<int, list<int>::iterator> posInOrderedFreqList;
    list<int> orderedFreqList;
    
    
    /** Initialize your data structure here. */
    AllOne() {
        revFreq.clear();
        freq.clear();
        posInOrderedFreqList.clear();
        orderedFreqList.clear();
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(freq[key].first != 0){
            revFreq[freq[key].first].erase(freq[key].second);
        }
        // inserting in orderedFreqList
        if(revFreq[freq[key].first+1].size() == 0){
            if(freq[key].first == 0){
                orderedFreqList.push_front(freq[key].first+1);
                posInOrderedFreqList[freq[key].first+1] = orderedFreqList.begin();
            } else {
                auto itr = posInOrderedFreqList[freq[key].first];
                itr = next(itr);
                orderedFreqList.insert(itr, freq[key].first+1);
                itr = prev(itr);
                posInOrderedFreqList[freq[key].first+1] = itr;
            }
        }
        // deleting in orderedFreqList
        if(freq[key].first != 0 and revFreq[freq[key].first].size() == 0){
            auto itr = posInOrderedFreqList[freq[key].first];
            posInOrderedFreqList.erase(freq[key].first);
            orderedFreqList.erase(itr);
        }
        freq[key].first++;
        revFreq[freq[key].first].push_front(key);
        freq[key].second = revFreq[freq[key].first].begin();
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(freq[key].first == 0) return;
        revFreq[freq[key].first].erase(freq[key].second);
        freq[key].first--;
        // inserting in orderedFreqList
        if(freq[key].first != 0 and revFreq[freq[key].first].size() == 0){
            auto itr = posInOrderedFreqList[freq[key].first+1];
            orderedFreqList.insert(itr, freq[key].first);
            itr = prev(itr);
            posInOrderedFreqList[freq[key].first] = itr;
        }
        // deleting in orderedFreqList
        if(revFreq[freq[key].first+1].size() == 0){
            auto itr = posInOrderedFreqList[freq[key].first+1];
            orderedFreqList.erase(itr);
            posInOrderedFreqList.erase(freq[key].first+1);
        }
        if(freq[key].first != 0){
            revFreq[freq[key].first].push_front(key);
            freq[key].second = revFreq[freq[key].first].begin();
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        int maxFreq = orderedFreqList.size()?*prev(orderedFreqList.end()):0;
        return maxFreq?revFreq[maxFreq].front():"";
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        int minFreq = orderedFreqList.size()?orderedFreqList.front():0;
        return minFreq?revFreq[minFreq].front():"";
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