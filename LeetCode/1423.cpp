// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

// Method 1 (Sliding Window, O(n)):

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), subarraySum = 0, totalSum = 0;
        for(int i=0; i<n-k; i++){
            subarraySum += cardPoints[i];
            totalSum += cardPoints[i];
        }
        int minSubarraySum = subarraySum;
        for(int i=n-k; i<n; i++){
            subarraySum += (cardPoints[i]-cardPoints[i-(n-k)]);
            minSubarraySum = min(minSubarraySum, subarraySum);
            totalSum += cardPoints[i];
        }
        return totalSum-minSubarraySum;
    }
};

// Method 2 (Prefix and Suffix DP, O(n)):

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> prefixSum(cardPoints);
        vector<int> suffixSum(cardPoints);
        for(int i=1; i<n; i++){
            prefixSum[i] += prefixSum[i-1];
        }
        for(int i=n-2; i>=0; i--){
            suffixSum[i] += suffixSum[i+1];
        }
        int maxScore = max(prefixSum[k-1], suffixSum[n-k]);
        for(int i=0; i<k-1; i++){
            maxScore = max(maxScore, prefixSum[i]+suffixSum[n-(k-1-i)]);
        }
        return maxScore;
    }
};

// Method 3:

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