// https://leetcode.com/problems/rank-transform-of-an-array/

// Method 1 (Sorting + Hash Map, O(nlogn)):

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        
        set<int> nums(arr.begin(), arr.end());

        int rank = 1;
        unordered_map<int, int> numToRank;
        
        for(int num:nums){
            numToRank[num] = rank;
            rank++;
        }

        for(int i=0; i<n; i++){
            arr[i] = numToRank[arr[i]];
        }

        return arr;
    }
};
