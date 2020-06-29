// https://leetcode.com/problems/h-index-ii/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), lo, hi, mid;
        if(n == 0) return 0;
        
        // p(i) : citations[i] >= (n-i)
        // FFTT
        // first true
        
        lo = 0;
        hi = n-1;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(citations[mid] >= (n-mid)){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        if(citations[lo] >= (n-lo)){
            return n-lo;
        } else {
            return 0;
        }
    }
};