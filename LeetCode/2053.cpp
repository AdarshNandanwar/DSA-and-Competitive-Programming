// https://leetcode.com/problems/kth-distinct-string-in-an-array/

// Method 1 (Hash Map, O(n)):

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freq;
        for(const string & s:arr){
            freq[s]++;
        }

        int distinct = 0;
        for(const string & s:arr){
            if(freq[s] == 1){
                distinct++;
            }
            if(distinct == k){
                return s;
            }
        }

        return "";
    }
};
