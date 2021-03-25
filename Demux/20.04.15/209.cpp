// https://leetcode.com/problems/minimum-size-subarray-sum/

// Method 1 (O(n)) BST map:

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), min_len = INT_MAX;
        map<int, int> m;
        
        // start i.e. when cumSum is 0
        m[0] = -1;
        
        int cumSum = 0;
        for(int i = 0; i<n; i++){
            
            cumSum += nums[i];
            m[cumSum] = i;
            
            auto it = m.upper_bound(cumSum-s);
            if(it != m.begin()){
                it--;
                min_len = min(min_len, i-it->second);
            }
        }
        return (min_len == INT_MAX)?0:min_len;
    }
};

// Method 2 (O(logn)) 2 pointers:

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int p1 = 0, p2 = 0, min_len = n+1, curr_sum = 0;
        while(p2<n){
            curr_sum += nums[p2];
            p2++;
            while(p1<p2 and curr_sum>=s){
                min_len = min(min_len, p2-p1);
                curr_sum -= nums[p1];
                p1++;
            }
        }
        if(min_len == n+1){
            return 0;
        } else {
            return min_len;
        }
    }
};