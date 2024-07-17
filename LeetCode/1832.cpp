// https://leetcode.com/problems/find-the-winner-of-the-circular-game/

// Method 1 (Josephus Problem, O(n) time, O(n) space):

class Solution {
    unordered_map<int, int> dp;
public:
    int findTheWinner(int n, int k) {
        if(n == 1){
            return 1;
        }
        if(dp.count(n)){
            return dp[n];
        }
        return dp[n] = ((findTheWinner(n-1, k) - 1 + k) % n) + 1;
    }
};
