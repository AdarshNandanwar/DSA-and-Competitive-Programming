// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int k_sum = 0, n = cardPoints.size(), res = 0;
        for(int i = 0; i<min(k, n); i++){
            k_sum += cardPoints[i];
        }
        res = max(res, k_sum);
        for(int i = 0; i<k; i++){
            k_sum += (cardPoints[n-1-i]-cardPoints[k-1-i]);
            res = max(res, k_sum);
        }
        return res;
    }
};