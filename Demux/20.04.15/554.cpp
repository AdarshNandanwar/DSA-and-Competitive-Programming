// https://leetcode.com/problems/brick-wall/

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        if(n == 0){
            return 0;
        }
        int max_cum = 0;
        unordered_map<long long int, int> mp;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<wall[i].size()-1; j++){
                if(j != 0)
                    wall[i][j] = wall[i][j]+wall[i][j-1];
                mp[wall[i][j]]++;
                max_cum = max(max_cum, mp[wall[i][j]]);
            }
        }
        return n-max_cum;                    
    }
};