// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/

// Method 1 (Hash Map and Modulo, O(n)):

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for(auto num:arr){
            freq[((num % k) + k) % k]++;
        }
        for(auto entry:freq){
            int compliment = ((k - entry.first) + k) % k;
            if(entry.first == compliment){
                if(entry.second % 2 == 1){
                    return false;
                }
            }
            if(entry.second != freq[compliment]){
                return false;
            }
        }
        return true;
    }
};
