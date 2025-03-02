// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/

// Method 1 (Hash Set and Sorting, O(nlogn)):

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> b(banned.begin(), banned.end());
        int count = 0;
        int curSum = 0;
        sort(banned.begin(), banned.end());
        for(int i=1; i<=n; i++){
            if(b.count(i)){
                continue;
            }
            curSum += i;
            if(curSum <= maxSum){
                count++;
            } else {
                return count;
            }
        }
        return count;
    }
};
