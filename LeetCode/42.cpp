// https://leetcode.com/problems/trapping-rain-water/

// Method 1 (2 Pointers, O(n) time, O(1) space):

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1, leftMax = -1, rightMax = -1;
        int water = 0;
        while(left<=right){
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if(leftMax < rightMax){
                water += (leftMax-height[left]);
                left++;
            } else {
                water += (rightMax-height[right]);
                right--;
            }
        }
        return water;
    }
};

// Method 2 (Stack, O(n) time, O(n) space):

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        // The stack contains decreasing values (not strictly decreasing)
        stack<int> decSt;
        for(int i=0; i<n; i++){
            while(!decSt.empty() and height[decSt.top()] < height[i]){
                int curHeight = height[decSt.top()];
                decSt.pop();
                if(!decSt.empty()){
                    int prevHeight = height[decSt.top()];
                    water += ((min(prevHeight, height[i])-curHeight)*(i-decSt.top()-1));
                }
            }
            decSt.push(i);
        }
        return water;
    }
};
