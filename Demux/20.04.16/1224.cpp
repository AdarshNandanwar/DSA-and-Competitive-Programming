// https://leetcode.com/problems/maximum-equal-frequency/

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, unordered_set<int>> revFreq;
        
        int n = nums.size(), max_len = 0, max_freq = 0;
        
        for(int i = 0; i<n; i++){
            freq[nums[i]]++;
            max_freq = max(max_freq, freq[nums[i]]);
            revFreq[freq[nums[i]]].insert(nums[i]);
            
            if(freq[nums[i]] != 1){
                revFreq[freq[nums[i]]-1].erase(nums[i]);
            }
            if((max_freq==i+1) ||
               (revFreq[1].size()==i+1) ||
               (revFreq[1].size()==1 && revFreq[max_freq].size()*max_freq==i) ||
               (revFreq[max_freq].size()==1 && revFreq[max_freq-1].size()*(max_freq-1)==i+1-max_freq)){
                max_len = i+1;
            }
        }
        
        return max_len;
    }
};