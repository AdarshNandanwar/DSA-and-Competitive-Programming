// https://leetcode.com/problems/sort-an-array/

// Method 1 (Radix Sort, O((n+base)*log[base](maxEle))):

class Solution {
public:
    void radixSort(vector<int>& nums){
        int n = nums.size();
        if(n == 0) return;
        int maxElement = *max_element(nums.begin(), nums.end());
        
        // Radix Sort
        for(long place=1; place<=maxElement; place*=10){
            vector<int> digitCount = vector<int>(10, 0);
            for(int i=0; i<n; i++){
                int digit = (nums[i]/place)%10;
                digitCount[digit]++;
            }
            for(int i=1; i<10; i++){
                digitCount[i] += digitCount[i-1];
            }
            vector<int> originalNums = vector<int>(nums);
            for(int i=n-1; i>=0; i--){
                int digit = (originalNums[i]/place)%10;
                digitCount[digit]--;
                nums[digitCount[digit]] = originalNums[i];
            }
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        vector<int> neg, pos;
        for(auto &i:nums){
            if(i<0){
                neg.push_back(-i);
            } else {
                pos.push_back(i);
            }
        }
        radixSort(pos);
        radixSort(neg);
        vector<int> ans;
        for(int i=neg.size()-1; i>=0; i--){
            ans.push_back(-neg[i]);
        }
        for(int i=0; i<pos.size(); i++){
            ans.push_back(pos[i]);
        }
        return ans;
    }
};

// Method 2 (Handling negative numbers in radix sort using bit manipulation, O((n+2)*log[2](maxEle))):

class Solution {
public:
    void radixSort(vector<int>& nums){
        int n = nums.size();
        if(n == 0) return;
        
        // Radix Sort
        for(long place=0; place<32; place++){
            vector<int> bitCount = vector<int>(2, 0);
            for(int i=0; i<n; i++){
                int bit = (((nums[i])>>place)&1);
                bitCount[bit]++;
            }
            bitCount[1] += bitCount[0];
            vector<int> originalNums = vector<int>(nums);
            for(int i=n-1; i>=0; i--){
                int bit = (((originalNums[i])>>place)&1);
                bitCount[bit]--;
                nums[bitCount[bit]] = originalNums[i];
            }
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        for(auto &i:nums) i=(i^(1<<31));
        radixSort(nums);
        for(auto &i:nums) i=(i^(1<<31));
        return nums;
    }
};

// Method 3 (Heap Sort, O(nlogn)):

class Solution {
public:    
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto &i:nums){
            pq.push(i);
        } 
        for(auto &i:nums){
            i = pq.top();
            pq.pop();
        }
        return nums;
    }
};