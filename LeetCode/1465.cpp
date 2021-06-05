// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int h_max = 0, v_max = 0;
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        for(int i = horizontalCuts.size()-1; i>0; i--){
            h_max = max(h_max, horizontalCuts[i]-horizontalCuts[i-1]);
        } 
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(verticalCuts.begin(), verticalCuts.end());
        for(int i = verticalCuts.size()-1; i>0; i--){
            v_max = max(v_max, verticalCuts[i]-verticalCuts[i-1]);
        }
        return ((long long)h_max*v_max)%1000000007;
    }
};