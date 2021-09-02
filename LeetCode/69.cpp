// https://leetcode.com/problems/sqrtx/

// Method 1 (Binary Search, O(logn)):

class Solution {
public:
    int mySqrt(int x) {
        long mid, lo = 0, hi = x;
        // FT last F
        while(lo<hi){
            mid = lo+(hi-lo+1)/2;
            if(mid*mid > x){
                hi = mid-1;
            } else {
                lo = mid;
            }
        }
        return lo;
    }
};