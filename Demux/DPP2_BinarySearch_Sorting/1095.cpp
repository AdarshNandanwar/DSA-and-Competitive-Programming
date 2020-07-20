// https://leetcode.com/problems/find-in-mountain-array/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length(), lo, hi, mid, peak, index;
        
        // find peak
        // p(i): mountainArr.get(i)>mountainArr.get(i+1)
        // FFTTT
        // First true
        lo = 1;
        hi = n-2;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(mountainArr.get(mid)>mountainArr.get(mid+1)){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        peak = lo;
        
        
        // Search in first half
        // p(i): mountainArr.get(i)>=target
        // FFTTT
        // First true
        lo = 0;
        hi = peak;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(mountainArr.get(mid)>=target){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        if(mountainArr.get(lo)==target){
            return lo;
        }
        
        // Search in second half
        // p(i): mountainArr.get(i)<=target
        // FFTTT
        // First true
        lo = peak;
        hi = n-1;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(mountainArr.get(mid)<=target){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        if(mountainArr.get(lo)==target){
            return lo;
        }
        
        return -1;
    }
};