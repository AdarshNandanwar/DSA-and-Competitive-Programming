// https://leetcode.com/problems/sum-of-distances-in-tree/

// Method 1 (O(n)):

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