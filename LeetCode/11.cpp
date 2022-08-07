// https://leetcode.com/problems/container-with-most-water/

// Method 1 (2 Pointer, O(n)):

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxWater = 0;
        int left = 0, right = n-1;
        while(left<right){
            int waterLevel = min(height[left], height[right]);
            int width = right-left;
            int water = waterLevel*width;
            maxWater = max(maxWater, water);
            if(height[left] < height[right]){
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
};