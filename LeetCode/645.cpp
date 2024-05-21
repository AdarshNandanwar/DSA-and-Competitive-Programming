// https://leetcode.com/problems/set-mismatch/description/

// Method 1 (Indexing, O(n)):

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(), repeatedNum;
        for(int i=0; i<n; i++){
            int index = abs(nums[i])-1;
            if(nums[index] < 0){
                repeatedNum = abs(nums[i]);
            } else {
                nums[index] *= -1;
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                return {repeatedNum, i+1};
            }
        }
        return {-1, -1};
    }
};

// Method 2 (Hash Table, XOR, O(n)):

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(), xorOfRepeatedAndMissing = 0, repeatedNum;
        unordered_set<int> s;
        for(int i=0; i<n; i++){
            if(s.count(nums[i])){
                repeatedNum = nums[i];
            }
            s.insert(nums[i]);
            xorOfRepeatedAndMissing ^= (i+1);
            xorOfRepeatedAndMissing ^= nums[i];
        }
        return {repeatedNum, xorOfRepeatedAndMissing^repeatedNum};
    }
};

// Method 3 (Hash Table, O(2*n)):

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(), repeatNum, missingNum;
        unordered_set<int> s;
        for(int i=0; i<n; i++){
            if(s.count(nums[i])){
                repeatNum = nums[i];
            }
            s.insert(nums[i]);
        }
        for(int i=1; i<=n; i++){
            if(s.count(i) == 0){
                missingNum = i;
            }
        }
        return {repeatNum, missingNum};
    }
};