// https://leetcode.com/problems/find-missing-observations/

// Method 1 (Math, O(n)):

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        for(int roll:rolls){
            sum += roll;
        }

        int targetSum = mean * (m + n) - sum;
        if(targetSum < n or 6 * n < targetSum){
            return {};
        }

        if(6 * n == targetSum){
            return vector(n, 6);
        }

        int baseNumber = targetSum / n;
        int baseSum = baseNumber * n;
        int increases = targetSum - baseSum;

        vector<int> missing(n, baseNumber);
        for(int i=0; i<increases; i++){
            missing[i]++;
        }

        return missing;
    }
};
