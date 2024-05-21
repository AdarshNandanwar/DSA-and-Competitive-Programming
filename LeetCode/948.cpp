// https://leetcode.com/problems/bag-of-tokens/

// Method 1 (Greedy, 2 Pointers, Sorting, O(nlogn)):

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int left = 0, right = n-1;
        int score = 0;
        int maxScore = 0;
        while(left <= right){
            while(left <= right and tokens[left] <= power){
                power -= tokens[left];
                score++;
                left++;
            }

            if(score == 0){
                break;
            }

            maxScore = max(maxScore, score);

            power += tokens[right];
            score--;
            right--;
        }
        return maxScore;
    }
};