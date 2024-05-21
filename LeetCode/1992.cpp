// https://leetcode.com/problems/find-all-groups-of-farmland/

// Method 1 (Brute Force, O(n*m) time, O(1) space):

class Solution {
    bool isTopLeft(const vector<vector<int>>& land, int i, int j){
        int n = land.size(), m = land[0].size();
        return (i-1<0 or land[i-1][j] == 0) and (j-1<0 or land[i][j-1] == 0);
    }
    void addGroup(const vector<vector<int>>& land, const int i, const int j, vector<vector<int>> & res){
        int n = land.size(), m = land[0].size();
        int iEnd = i, jEnd = j;
        while(iEnd+1<n and land[iEnd+1][j]){
            iEnd++;
        }
        while(jEnd+1<m and land[i][jEnd+1]){
            jEnd++;
        }
        res.push_back({i, j, iEnd, jEnd});
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();
        vector<vector<int>> res;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(land[i][j] == 1 and isTopLeft(land, i, j)){
                    addGroup(land, i, j, res);
                }
            }
        }
        return res;
    }
};
