// https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/

// Method 1 (2D DP, O(mn^2)):

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> dist(n, vector<int>(n)); // dist[i][j] = shortest distance from i to j
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                dist[i][j] = j-i;
            }
        }

        int m = queries.size();
        vector<int> answer(m);
        for(int q=0; q<m; q++){
            int src = queries[q][0];
            int dest = queries[q][1];
            for(int i=src; i>=0; i--){
                for(int j=dest; j<n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][src] + 1 + dist[dest][j]);
                }
            }
            answer[q] = dist[0][n-1];
        }

        return answer;
    }
};
