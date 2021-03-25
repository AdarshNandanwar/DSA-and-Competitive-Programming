// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cumStart(n, 0), cumEnd(n, 0), ans;
        
        // cumStart[i] = max sum of (i-k,i] from left
        cumStart[0] = nums[0];
        for(int i = 1; i<n; i++){
            cumStart[i] = cumStart[i-1]+nums[i];
            if(i-k>=0) cumStart[i] -= nums[i-k];
        }
        for(int i = 1; i<n; i++) cumStart[i] = max(cumStart[i], cumStart[i-1]);
        
        // cumEnd[i] = max sum of [i,i+k) from right
        cumEnd[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--){
            cumEnd[i] = cumEnd[i+1]+nums[i];
            if(i+k<n) cumEnd[i] -= nums[i+k];
        }
        // windowSum[i] = sum of [i,i+k)
        vector<int> windowSum(cumEnd.begin(), cumEnd.end());
        for(int i = n-2; i>=0; i--) cumEnd[i] = max(cumEnd[i], cumEnd[i+1]);
        
        int s1, s2, s3, ss, I;
        s1 = s2 = s3 = ss = 0, I = 0;
        
        for(int i = k; i+k+k<=n; i++){
            if(ss < cumStart[i-1]+windowSum[i]+cumEnd[i+k]){
                I = i;
                s1 = cumStart[i-1];
                s2 = windowSum[i];
                s3 = cumEnd[i+k];
                ss = s1+s2+s3;
            }
        }
        
        ans.push_back(lower_bound(cumStart.begin(), cumStart.begin()+I-1, s1)-cumStart.begin()-(k-1));
        ans.push_back(I);
        for(int i = I+k; i<n; i++){
            if(windowSum[i] == s3){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};