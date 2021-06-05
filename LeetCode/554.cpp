// https://leetcode.com/problems/brick-wall/

// Method 1 (DP, Cumulative Sum)

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        if(n == 0) return 0;
        unordered_map<int, int> freq;
        for(int i = 0; i<n; i++){
            int m = wall[i].size();
            for(int j = 0; j<m; j++){
                if(j != 0) wall[i][j] += wall[i][j-1];
                if(j != m-1) freq[wall[i][j]]++;
            }
        }
        int ans = n;
        for(auto i:freq) ans = min(ans, n-i.second);
        return ans;
    }
};