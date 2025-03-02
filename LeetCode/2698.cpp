// https://leetcode.com/problems/find-the-punishment-number-of-an-integer/

// Method 1 (Recursion, O(n*2^(logn)) time):

class Solution {
    bool isValid(int n, int target){
        if(n < target){
            return false;
        }
        if(n == target){
            return true;
        }
        for(int i=10; n/i>0 and target>=n%i; i*=10){
            if(isValid(n/i, target-(n%i))){
                return true;
            }
        }
        return false;
    }
public:
    int punishmentNumber(int n) {
        int sum = 0;
        for(int i=1; i<=n; i++){
            if(isValid(i*i, i)){
                sum += (i*i);
            }
        }
        return sum;
    }
};
