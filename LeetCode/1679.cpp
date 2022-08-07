// https://leetcode.com/problems/max-number-of-k-sum-pairs/

// Method 1 (Hash map, O(n) time, O(n) space):

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int> freq;
        for(int i=0; i<n; i++){
            int target = k-nums[i];
            if(freq.count(target)){
                ans++;
                freq[target]--;
                if(freq[target] == 0){
                    freq.erase(target);
                }
            } else {
                freq[nums[i]]++;
            }
        }
        return ans;
    }
};

// Method 2 (Sorting, 2 Pointer, O(nlogn) time, O(1) space):

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        int p1 = 0, p2 = n-1;
        while(p1<p2 and nums[p1]<k){    // pruning (element>=1)
            int sum = nums[p1]+nums[p2];
            if(sum == k){
                ans++;
                p1++;
                p2--;
            } else if (sum < k){
                p1++;
            } else {
                p2--;
            }
        }
        return ans;
    }
};