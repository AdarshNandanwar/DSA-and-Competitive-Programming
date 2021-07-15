// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

// Method 1 (O(n)):

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p1 = 0, p2 = numbers.size()-1;
        while(p1<p2){
            if(numbers[p1]+numbers[p2] > target) p2--;
            else if(numbers[p1]+numbers[p2] < target) p1++;
            else return {p1+1, p2+1};
        }
        return {0,0};
    }
};