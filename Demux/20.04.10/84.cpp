// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st1;
        vector<int> next(n, n);
        for(int i = 0; i<n; i++){
            while(!st1.empty() && heights[i]<heights[st1.top()]){
                next[st1.top()] = i;
                st1.pop();
            }
            st1.push(i);
        }
        stack<int> st2;
        vector<int> prev(n, -1);
        for(int i = n-1; i>=0; i--){
            while(!st2.empty() && heights[i]<heights[st2.top()]){
                prev[st2.top()] = i;
                st2.pop();
            }
            st2.push(i);
        }
        int ans = 0;
        for(int i =0; i<n; i++){
            ans = max(ans, heights[i]*(next[i]-prev[i]-1));
        }
        return ans;
    }
};