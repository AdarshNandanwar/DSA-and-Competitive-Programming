// https://leetcode.com/problems/longest-turbulent-subarray/

// Method 1 (Dynamic Programming):

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size(), maxLen = 1;
        if(n == 0) return 0;
        // length of longest subarray ending at i
        vector<pair<int, int>> dp(n, {1, 1});  // inc, dec
        for(int i =1; i<n; i++){
            if(A[i]>A[i-1]){
                dp[i].first = dp[i-1].second+1;
            } else if(A[i]<A[i-1]){
                dp[i].second = dp[i-1].first+1;
            }
            maxLen = max(maxLen, max(dp[i].first, dp[i].second));
        }
        return maxLen;
    }
};

// Method 2 (2 Pointers):

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int p1 = 0, p2 = 0, max_len = 1, next, n = A.size();
        
        while(p2<n){
            p2++;
            if(p2<n && p1 == p2-1){
                if(A[p1] < A[p2]){
                    next = 0;
                } else if(A[p1] > A[p2]){
                    next = 1;
                } else {
                    p1++;
                }
            } else {
                if(p2<n && next && A[p2]>A[p2-1]){
                    next = 0;
                } else if(p2<n && !next && A[p2-1]>A[p2]){
                    next = 1;
                } else {
                    max_len = max(max_len, p2-p1);
                    p1 = p2-1;
                    if(p2>=n) continue;
                    if(A[p1] < A[p2]){
                        next = 0;
                    } else if(A[p1] > A[p2]){
                        next = 1;
                    } else {
                        p1++;
                    }
                }
            }
        }
        max_len = max(max_len, p2-p1);
        return max_len;
    }
};