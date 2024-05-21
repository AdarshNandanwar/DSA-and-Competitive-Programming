// https://leetcode.com/problems/freedom-trail/

// Method 1 (2D DP, O(n*n*(m+n)) time, O(n*m) space):

class Solution {
    int getSteps(int src, int dest, int size){
        return min((size+dest-src)%size, (size+src-dest)%size);
    }

    int getCost(const string & ring, const string & key, int pos, int index, const vector<vector<vector<int>>> & nbrs, vector<vector<int>> & dp){
        int n = ring.size(), m = key.size();
        if(index == m){
            return 0;
        }
        if(dp[pos][index] != -1){
            return dp[pos][index];
        }
        int cost = 1e4;
        for(int nbr:nbrs[pos][key[index]-'a']){
            cost = min(cost, getSteps(pos, nbr, n) + getCost(ring, key, nbr, index+1, nbrs, dp));
        }
        return dp[pos][index] = cost;
    }
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<vector<vector<int>>> nbrs(n, vector<vector<int>>(26));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                nbrs[i][ring[j]-'a'].push_back(j);
            }
        }
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return getCost(ring, key, 0, 0, nbrs, dp) + m;
    }
};
