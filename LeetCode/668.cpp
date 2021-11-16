// https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/

// Method 1 (Binary Search, O(m*log(m*n))):

class Solution {
public:
    int count(int m, int n, int x){
        // count of numbers <= x
        int res = 0;
        for(int i = 1; i<=m; i++) res += min(n, x/i);
        return res;
    }
    
    int findKthNumber(int m, int n, int k) {
        // Binary Search
        // FT first T
        int lo = 1, hi = m*n, mid;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(count(m, n, mid) >= k){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        return lo;
    }
};