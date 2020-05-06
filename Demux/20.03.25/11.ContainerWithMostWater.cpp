class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int p1 = 0, p2 = n-1;
        int maxArea = 0;
        while(p1<=p2){
            int area = (p2-p1)*min(height[p1], height[p2]);
            maxArea = max(maxArea, area);
            if(height[p1]<height[p2]){
                p1++;
            } else {
                p2--;
            }
        }
        return maxArea;
    }
};