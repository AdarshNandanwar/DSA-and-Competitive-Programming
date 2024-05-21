// https://leetcode.com/problems/unique-number-of-occurrences/description/

// Method 1 (Hash Map, O(n)):

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(auto i:arr){
            freq[i]++;
        }
        unordered_set<int> freqSet;
        for(auto i:freq){
            if(freqSet.count(i.second)){
                return false;
            }
            freqSet.insert(i.second);
        }
        return true;
    }
};