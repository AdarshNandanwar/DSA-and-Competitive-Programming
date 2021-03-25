// https://leetcode.com/problems/count-number-of-nice-subarrays/

// Method 1 (using 2 pointer, subarray template)

class Solution {
public:
    int numberOfSubarraysAtmostK(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        int p1 = 0, p2 = 0, odd = 0;
        while(p2<n){
            if(nums[p2]&1){
                odd++;
            }
            p2++;
            
            while(p1<p2 && odd>k){
                if(nums[p1]&1){
                    odd--;
                }
                p1++;
            }
            ans += (p2-p1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numberOfSubarraysAtmostK(nums, k)-numberOfSubarraysAtmostK(nums, k-1);
    }
};

// Method 2 (Custom logic)

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int p1 = 0, p2 = 0, odd = 0, count = 0, prev = 0;
        while(p2<n){
            if(nums[p2]%2){
                if(odd == k){
                    int prefix = 0;
                    while(p1<p2 && nums[p1]%2 == 0){
                        prefix++;
                        p1++;
                    }
                    int suffix = p2-prev-1;
                    count += ((prefix+1)*(suffix+1));
                    p1++;
                    odd--;
                }
                odd++;
                prev = p2;
            }
            p2++;
        }
        if(odd == k){
            int prefix = 0;
            while(p1<p2 && nums[p1]%2 == 0){
                prefix++;
                p1++;
            }
            int suffix = p2-prev-1;
            count += ((prefix+1)*(suffix+1));
            p1++;
            odd--;
        }
        return count;
    }
};