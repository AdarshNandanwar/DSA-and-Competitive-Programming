// https://leetcode.com/problems/guess-number-higher-or-lower/

// Method 1 (Binary Search, O(logn)):

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1, hi = n, mid;
        // mid < pick
        // TF first F
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(guess(mid) == 1){
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        if(guess(lo) == 0) return lo;
        return -1;
    }
};