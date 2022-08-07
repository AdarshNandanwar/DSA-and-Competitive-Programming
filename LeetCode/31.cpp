// https://leetcode.com/problems/next-permutation/

// Method 1 (STL Binary Search, O(n)):

class Solution {
public:    
    void nextPermutation(vector<int>& nums) {        
        int n = nums.size();
        int firstLow = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                firstLow = i;
                break;
            }
        }
        if(firstLow == -1){
            reverse(nums.begin(), nums.end());
        } else {
            int newDigitIndex = nums.rend()-upper_bound(nums.rbegin(), nums.rend()-1-firstLow, nums[firstLow])-1;
            swap(nums[firstLow], nums[newDigitIndex]);
            reverse(nums.begin()+firstLow+1, nums.end());
        }
    }
};

// Method 2 (Custom Binary Search, O(n)):

class Solution {
public:
    int reverseUpperBound(const vector<int>& nums, int lo, int hi, const int & target){
        // TF, Last T
        int mid;
        while(lo<hi){
            mid = lo+(hi-lo+1)/2;
            if(nums[mid] > target){
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        if(nums[lo] > target) return lo;
        else return -1;
    }
    
    void nextPermutation(vector<int>& nums) {        
        int n = nums.size();
        int firstLow = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                firstLow = i;
                break;
            }
        }
        if(firstLow == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        int newDigitIndex = reverseUpperBound(nums, firstLow+1, n-1, nums[firstLow]);
        swap(nums[firstLow], nums[newDigitIndex]);
        reverse(nums.begin()+firstLow+1, nums.end());
        return;
    }
};