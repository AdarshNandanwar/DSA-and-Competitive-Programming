// https://leetcode.com/problems/sum-of-distances-in-tree/

// Method 1 (DFS, O(n)):

class Solution {
public:
    
    // {dist_sum, node_count}
    vector<int> generate_data(int root, vector<vector<int>>& adj_list, vector<bool>& visited, vector<vector<int>>& data){
        visited[root] = true;
        int dist_sum = 0, node_count = 0;
        for(auto &nbr:adj_list[root]){
            if(visited[nbr]) continue;
            auto res = generate_data(nbr, adj_list, visited, data);
            dist_sum += (res[0]+res[1]);
            node_count += res[1];
        }
        return data[root] = {dist_sum, 1+node_count};
    }
    
    void helper(int root, vector<vector<int>>& adj_list, vector<bool>& visited, vector<vector<int>>& data, vector<int>& ans){
        visited[root] = true;
        ans[root] = data[root][0];
        for(auto &nbr:adj_list[root]){
            if(visited[nbr]) continue;
            auto temp_root_data = data[root];
            auto temp_nbr_data = data[nbr];
            data[root] = {temp_root_data[0]-(temp_nbr_data[0]+temp_nbr_data[1]), temp_root_data[1]-temp_nbr_data[1]};
            data[nbr] = {temp_nbr_data[0]+(data[root][0]+data[root][1]), temp_nbr_data[1]+data[root][1]};
            helper(nbr, adj_list, visited, data, ans);
            data[root] = temp_root_data;
            data[nbr] = temp_nbr_data;
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj_list(n);
        for(auto & e:edges){
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        
        vector<bool> visited(n, false);
        vector<vector<int>> data(n);
        generate_data(0, adj_list, visited, data);
        
        visited = vector<bool>(n, false);
        vector<int> ans(n, 0);       
        helper(0, adj_list, visited, data, ans);
        
        return ans;
    }
};

// Alternate Code:

class Solution {
    int fillSubtreeSize(const vector<vector<int>> & nbrs, int pos, vector<bool> & visited, vector<int> & subtreeSize){
        if(visited[pos] == true){
            return 0;
        }
        visited[pos] = true;
        subtreeSize[pos] = 1;
        for(auto nbr:nbrs[pos]){
            subtreeSize[pos] += fillSubtreeSize(nbrs, nbr, visited, subtreeSize);
        }
        return subtreeSize[pos];
    }
    int getDistanceSum(const vector<vector<int>> & nbrs, int pos, vector<bool> & visited, const vector<int> & subtreeSize){
        if(visited[pos] == true){
            return 0;
        }
        visited[pos] = true;
        int distanceSum = 0;
        for(auto nbr:nbrs[pos]){
            if(visited[nbr]){
                continue;
            }
            distanceSum += (getDistanceSum(nbrs, nbr, visited, subtreeSize) + subtreeSize[nbr]);
        }
        return distanceSum;
    }
    void populateAllDistanceSum(const vector<vector<int>> & nbrs, int pos, const int treeSize, vector<bool> & visited, const vector<int> & subtreeSize, vector<int> & distanceSum){
        if(visited[pos] == true){
            return;
        }
        visited[pos] = true;
        for(auto nbr:nbrs[pos]){
            if(visited[nbr]){
                continue;
            }
            distanceSum[nbr] = (distanceSum[pos] + treeSize - 2*subtreeSize[nbr]);
            populateAllDistanceSum(nbrs, nbr, treeSize, visited, subtreeSize, distanceSum);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> nbrs(n);
        for(auto & edge:edges){
            nbrs[edge[0]].push_back(edge[1]);
            nbrs[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        vector<int> subtreeSize(n, 0);
        fillSubtreeSize(nbrs, 0, visited, subtreeSize);

        visited = vector<bool>(n);
        vector<int> distanceSum(n);
        distanceSum[0] = getDistanceSum(nbrs, 0, visited, subtreeSize);

        visited = vector<bool>(n);
        int treeSize = subtreeSize[0];
        populateAllDistanceSum(nbrs, 0, treeSize, visited, subtreeSize, distanceSum);

        return distanceSum;
    }
};

// Method 2 (Brute Force DFS, O(n2), TLE):

class Solution {
public:
    
    // {dist_sum, node_count}
    vector<int> helper(int node, vector<vector<int>>& adj_list, vector<bool>& visited){
        visited[node] = true;
        int dist_sum = 0, node_count = 0;
        for(auto &i:adj_list[node]){
            if(visited[i]) continue;
            auto res = helper(i, adj_list, visited);
            dist_sum += (res[0]+res[1]);
            node_count += res[1];
        }
        return {dist_sum, 1+node_count};
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj_list(n);
        for(auto & e:edges){
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        vector<int> ans(n);
        for(int i = 0; i<n; i++){
            vector<bool> visited(n, false);
            ans[i] = helper(i, adj_list, visited)[0];
        }
        return ans;
    }
};