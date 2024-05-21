// https://leetcode.com/problems/maximize-happiness-of-selected-children/

// Method 1 (Sorting, O(nlogn)):

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long happinessSum = 0;
        for(int i=0; i<k; i++){
            int currentHappiness = happiness[i]-i;
            if(currentHappiness <= 0){
                return happinessSum;
            }
            happinessSum += currentHappiness;
        }
        return happinessSum;
    }
};
