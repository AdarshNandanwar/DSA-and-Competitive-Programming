// https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    
    int calculateHours(vector<int>& piles, int k){
        int hours = 0;
        for(auto i:piles){
            hours += ceil((float)i/k);
        }
        return hours;
    }
    
    int minEatingSpeed(vector<int>& piles, int H) {
        int n = piles.size(), lo, hi, mid, speed;
        
        // p(i): calculateHours(i)<=H
        // FFFTTT
        // first true
        
        lo = 1;
        hi = *max_element(piles.begin(), piles.end());
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(calculateHours(piles, mid)<=H){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        return lo;
    }
};