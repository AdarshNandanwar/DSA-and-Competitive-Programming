// https://leetcode.com/problems/max-consecutive-ones-iii/

// Method 1 (2 Pointers, O(n)):

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size(), p1 = 0, p2 = 0, zeros = 0, maxLen = 0;
        // [p1, p2)
        while(p2<n){
            if(A[p2++] == 0) zeros++;
            while(zeros>K) if(A[p1++] == 0) zeros--;
            maxLen = max(maxLen, p2-p1);
        }
        return maxLen;
    }
};