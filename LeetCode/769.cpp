// https://leetcode.com/problems/max-chunks-to-make-sorted/

// Method 1 (Loop, O(n)):

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int curMax = 0;
        int chunks = 0;
        for(int i=0; i<n; i++){
            curMax = max(curMax, arr[i]);
            if(curMax == i){
                chunks++;
            }
        }
        return chunks;
    }
};
