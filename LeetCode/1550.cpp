// https://leetcode.com/problems/three-consecutive-odds/

// Method 1 (Loop, O(n)):

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int oddChainLength = 0;
        for(auto num:arr){
            if(num % 2 == 1){
                oddChainLength++;
            } else {
                oddChainLength = 0;
            }
            if(oddChainLength == 3){
                return true;
            }
        }
        return false;
    }
};
