// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/

// Method 1 (Binary Search, O(nlogk)):

class Solution {
    bool fits(int n, vector<int>& quantities, int x){
        if(x == 0){
            return false;
        }
        int m = quantities.size();
        int storesDistributed = 0;
        int index = 0;
        while(index < m){
            int quantitiy = quantities[index];
            while(quantitiy > 0){
                if(storesDistributed >= n){
                    return false;
                }
                storesDistributed++;
                quantitiy -= x;
            }
            index++;
        }
        return true;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        int lo = 0, mid = 0, hi = *max_element(quantities.begin(), quantities.end());
        // FT First T
        while(lo < hi){
            mid = lo + (hi-lo)/2;
            if(fits(n, quantities, mid)){
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        // There will always be a solution in [lo, hi]
        return lo;
    }
};
