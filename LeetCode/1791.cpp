// https://leetcode.com/problems/find-center-of-star-graph/

// Method 1 (Greedy, O(1) time, O(1) space):

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if(edges[0][0] == edges[1][0] or edges[0][0] == edges[1][1]){
            return edges[0][0];
        } else {
            return edges[0][1];
        }
    }
};

// Method 2 (Hash Map, O(n) time, O(n) space):

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n_edges = edges.size();
        int n = n_edges + 1;
        vector<int> degree(n+1, 0);
        for(auto & edge:edges){
            degree[edge[0]]++;
            degree[edge[1]]++;
            if(degree[edge[0]] == n-1){
                return edge[0];
            }
            if(degree[edge[1]] == n-1){
                return edge[1];
            }
        }
        return -1;
    }
};
