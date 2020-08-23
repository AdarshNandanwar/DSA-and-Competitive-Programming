// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/

class Solution {
public:
    
    vector<vector<int>> rects;
    int areaSum;
    
    Solution(vector<vector<int>>& rects) {
        // weighted mean wrt area of the rectangle
        // uniform probability
        // = (number_of_points_in_rectangle/total_number_of_points)*(1/number_of_points_in_rectangle)
        // = 1/total_number_of_points
        
        this->rects = rects;
        areaSum = 0;
        for(auto rect:rects) areaSum += getArea(rect);
    }
    
    int getArea(vector<int> r){
        return (r[2]-r[0]+1)*(r[3]-r[1]+1);
    }
    
    vector<int> pick() {
        int r = 0, n = rects.size();
        int selection = rand()%areaSum;
        for(r = 0; r<n and selection>=0; r++) selection -= getArea(rects[r]);
        r--;
        int base = rects[r][2]-rects[r][0]+1, height = rects[r][3]-rects[r][1]+1;
        return {rects[r][0]+rand()%base, rects[r][1]+rand()%height};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */