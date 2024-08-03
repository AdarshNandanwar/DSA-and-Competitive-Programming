// https://leetcode.com/problems/count-number-of-nice-subarrays/

// Method 1 (2 Pointer, O(n) time, O(1) space):

class Solution {
    int numberOfAtMostKOddSubarrays(const vector<int>& nums, int k){
        int n = nums.size();
        int p1 = 0, p2 = 0, odd = 0, count = 0;
        while(p2<n){
            if(p2<n and odd<=k){
                if(nums[p2]%2 == 1){
                    odd++;
                }
                p2++;
            }
            while(p1<p2 and odd>k){
                if(nums[p1]%2 == 1){
                    odd--;
                }
                p1++;
            }
            // [p1, p2)
            count += (p2-p1);
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numberOfAtMostKOddSubarrays(nums, k)-numberOfAtMostKOddSubarrays(nums, k-1);
    }
};

// Method 2 (Indexes, O(n) time, O(n) space):

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> oddPos;
        oddPos.push_back(-1);
        for(int i=0; i<n; i++){
            if(nums[i]%2 == 1){
                oddPos.push_back(i);
            }
        }
        oddPos.push_back(n);

        int nice = 0;
        for(int i=k; i<oddPos.size()-1; i++){
            nice += (oddPos[i-k+1]-oddPos[i-k])*(oddPos[i+1]-oddPos[i]);
        }
        return nice;
    }
};
