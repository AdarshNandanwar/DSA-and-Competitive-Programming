// https://leetcode.com/problems/arranging-coins/

// Method 1 (Binary Search, O(logn)):

class Solution {
public:
    bool is_valid(int n, long k){
        return k*(k+1) <= 2l*n;
    }
    
    int arrangeCoins(int n) {
        long lo = 1, hi = 1<<16, mid;
        // TF last T
        while(lo<hi){
            mid = lo+(hi-lo+1)/2;
            if(is_valid(n, mid)){
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        if(is_valid(n, lo)) return lo;
        else return -1;
    }
};

// Method 2 (O(n)):

class Solution {
public:
    int arrangeCoins(int n) {
        int ans = sqrt(2l*n);
        while((ans-1l)*(ans) <= 2l*n) ans++;
        return ans-2;
    }
};