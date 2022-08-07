// https://leetcode.com/problems/max-chunks-to-make-sorted-ii/

// Method 1 (Prefix sum, O(nlogn)):

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // [1,1,0,1,1]
        // [0,0,1,1,1]
        vector<int> sortedArr(arr);
        sort(sortedArr.begin(), sortedArr.end());
        int n = arr.size(), chunks=0;
        long prefixSum = 0, prefixSumSorted = 0;
        for(int i=0; i<n; i++){
            prefixSum += arr[i];
            prefixSumSorted += sortedArr[i]--;
            if(prefixSum == prefixSumSorted){
                chunks++;
            }
        }
        return chunks;
    }
};

// Method 2 (Hash Map, O(n2)):

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // [1,1,0,1,1]
        // [0,0,1,1,1]
        vector<int> sortedArr(arr);
        sort(sortedArr.begin(), sortedArr.end());
        unordered_map<int, int> freq;
        int n = arr.size(), chunks=0;
        for(int i=0; i<n; i++){
            freq[arr[i]]++;
            freq[sortedArr[i]]--;
            bool valid = true;
            for(auto &i:freq){
                if(i.second != 0){
                    valid = false;
                    break;
                }
            }
            if(valid){
                chunks++;
            }
        }
        return chunks;
    }
};