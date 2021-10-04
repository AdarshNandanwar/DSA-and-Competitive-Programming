// https://leetcode.com/problems/find-the-winner-of-the-circular-game/

// Method 1 (Josephus Problem, DP, O(n)):

class Solution {
public:
    // Josephus Problem. Convert to 0 based then solve.
    int findTheWinner(int n, int k) {
        if(n == 1) return 1;
        return (findTheWinner(n-1, k)-1+k)%n+1;
    }
};