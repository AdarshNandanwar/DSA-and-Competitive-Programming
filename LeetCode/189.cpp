// https://leetcode.com/problems/rotate-array/

// Method 1 (Graph Cycle, O(n) time, O(1) space):

class Solution {
public:
    int gcd(int a, int b){
        return b ? gcd(b, a%b) : a;
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int cycleLen = n/gcd(n, k), remaining = n;
        for(int i=0; i<n and remaining>0; i++){
            int val = nums[i], index = i, nextIndex;
            for(int j=0; j<cycleLen; j++){
                nextIndex = (n+index-k)%n;
                nums[index] = nums[nextIndex];
                index = nextIndex;
                remaining--;
            }
            nums[(i+k)%n] = val;
        }
    }
};