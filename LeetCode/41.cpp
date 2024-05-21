// https://leetcode.com/problems/first-missing-positive/

// Method 1 (Extending negative index logic to negative index value vectors, O(n) time, O(1) space):

class Solution {
    bool isPresent(const vector<int>& nums, int pivot, int value){
        int n = nums.size();
        int index = value-1;
        if(index>=pivot){
            return nums[index] < 0;
        } else {
            return nums[index] > 0;
        }
    }
    void markPresent(vector<int>& nums, int value){
        int n = nums.size();
        int index = value-1;
        nums[index] *= -1;
    }
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // Replace 0 with -1 to store isPresent using sign
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                nums[i] = -1;
            }
        }
        // Replace INT_MIN with -1 to avoid int overflow
        for(int i=0; i<n; i++){
            if(nums[i] == INT_MIN){
                nums[i] = -1;
            }
        }
        // Alternatively, we can replace all values <= 0 with -1 as we don't care about them
        // Group positive numbers together using pivot sort logic
        int p1 = 0, p2 = n-1;
        while(p1<=p2){
            if(nums[p1] > 0){
                int temp = nums[p2];
                nums[p2] = nums[p1];
                nums[p1] = temp;
                p2--;
            } else {
                p1++;
            }
        }
        // Now we can use opposite signs to indicate that index+1 is present
        int pivot = p1;
        // Values at index i>=pivot is positive, and i<pivot is negative
        for(int i=pivot; i<n; i++){
            // All i>= pivot should be originally positive
            int value = abs(nums[i]);
            // Keep in mind, there is no 0 in the vector and we don't care about numbers > n
            // as we want to find the first missing number between [1,n]
            if(value > n){
                continue;
            }
            if(!isPresent(nums, pivot, value)){
                markPresent(nums, value);
            }
        }
        // Find the first missing positive number
        for(int i=1; i<=n; i++){
            if(!isPresent(nums, pivot, i)){
                return i;
            }
        }
        return n+1;
    }
};

// Method 2 (Hash Map, O(n) time, O(n) space):

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> found(n+1, false);
        for(const int num:nums){
            if(num > 0 and num <= n){
                found[num] = true;
            }
        }
        for(int i=1; i<=n; i++){
            if(found[i] == false){
                return i;
            }
        }
        return n+1;
    }
};

// Method 3 (Sorting, O(nlogn) time, O(1) space):

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int firstPositiveValueIndex = -1;
        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                firstPositiveValueIndex = i;
                break;
            }
        }
        if(firstPositiveValueIndex == -1){
            return 1;
        }
        int expected = 1;
        for(int i = firstPositiveValueIndex; i<n; i++){
            if(nums[i] != expected){
                if(i-1>=0 and nums[i-1]==expected){
                    if(nums[i] == expected+1){
                        expected++;
                    } else {
                        return expected+1;
                    }
                } else {
                    return expected;
                }
            }
        }
        return nums[n-1] == expected ? expected+1 : expected;
    }
};
