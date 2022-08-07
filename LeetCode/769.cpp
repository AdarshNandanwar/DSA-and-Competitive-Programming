// https://leetcode.com/problems/max-chunks-to-make-sorted/

// Method 1 (O(n)):

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int nextChunkStart = 0, maxVal = -1, chunks = 0;
        for(int i=0; i<n; i++){
            maxVal = max(maxVal, arr[i]);
            if(i == maxVal){
                nextChunkStart = i+1;
                chunks++;
            }
        }
        return chunks;
    }
};