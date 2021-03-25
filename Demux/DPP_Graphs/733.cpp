// https://leetcode.com/problems/flood-fill/

int dir[5] = {0, 1, 0, -1, 0};

class Solution {
public:
    
    void helper(vector<vector<int>>& image, int sr, int sc, int & oldColor, int & newColor, int & n, int & m){
        if(sr<0 or sr>=n or sc<0 or sc>=m or image[sr][sc] != oldColor) return;
        image[sr][sc] = newColor;
        for(int i = 0; i<4; i++){
            helper(image, sr+dir[i], sc+dir[i+1], oldColor, newColor, n, m);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size(), m = image[0].size(), oldColor = image[sr][sc];
        if(oldColor != newColor) helper(image, sr, sc, oldColor, newColor, n, m);
        return image;
    }
};