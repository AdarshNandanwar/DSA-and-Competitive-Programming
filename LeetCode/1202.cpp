// https://leetcode.com/problems/smallest-string-with-swaps/

// Method 1 (Union Find with rank and path compression, O((E+V)logV)):

class Solution {
    int root(int x, vector<int> & id){
        if(x == id[x]){
            return x;
        }
        return id[x] = root(id[x], id);
    }
    
    void merge(int r1, int r2, vector<int> & id, vector<int> & sz){
        if(sz[r1] < sz[r2]){
            swap(r1, r2);
        }
        sz[r1] += sz[r2];
        id[r2] = id[r1];
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        vector<int> id(n), sz(n, 1);
        for(int i=0; i<n; i++){
            id[i] = i;
        }
        for(auto &edge:pairs){
            int r1 = root(edge[0], id);
            int r2 = root(edge[1], id);
            if(r1 == r2){
                continue;
            }
            merge(r1, r2, id, sz);
        }
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> groups;
        for(int i=0; i<n; i++){
            int cur_id = root(i, id);
            groups[cur_id].push(s[i]);
        }
        string res = "";
        for(int i=0; i<n; i++){
            int cur_id = root(i, id);
            char next = groups[cur_id].top();
            res.push_back(next);
            groups[cur_id].pop();
        }
        return res;
    }
};