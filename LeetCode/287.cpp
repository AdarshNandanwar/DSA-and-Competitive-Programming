// https://leetcode.com/problems/find-the-duplicate-number/

// Method 1 (Floyd's Slow Fast Pointer Method, Without vector modification, O(n) time, O(1) space):

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = 0;
        int fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

// Method 2 (Negative value method, With vector modification, O(n) time, O(1) space):

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int num = abs(nums[i]);
            if(nums[num] < 0){
                return num;
            }
            nums[num] *= -1;
        }
        return -1;
    }
};

// Method 3 (Hash set, O(n) time, O(n) space):

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0; i<nums.size(); i++){
            if(s.count(nums[i])) return nums[i];
            s.insert(nums[i]);
        }
        return -1;
    }
};
