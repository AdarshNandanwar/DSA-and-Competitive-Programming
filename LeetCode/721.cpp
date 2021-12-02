// https://leetcode.com/problems/accounts-merge/

// Method 1 (Union Find with rank and path compression):

class Solution {
public:
    string root(unordered_map<string, string> & id, string x){
        if(id[x] == x) return x;
        return id[x] = root(id, id[x]);
    }
    void merge(unordered_map<string, string> & id, unordered_map<string, string> & sz, string r1, string r2){
        if(sz[r1] < sz[r2]) swap(r1, r2);
        sz[r1] += sz[r2];
        id[r2] = id[r1];
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> id, sz, name;
        for(auto & account:accounts){
            for(int i=1; i<account.size(); i++){
                name[account[i]] = account[0];
                if(id.count(account[i])){
                    string r1 = root(id, account[i]);
                    string r2 = root(id, id[account[i]]);
                    if(r1 != r2) merge(id, sz, r1, r2);
                } else {
                    id[account[i]] = account[i];
                    sz[account[i]] = 1;
                }
                string r1 = root(id, account[i]);
                string r2 = root(id, account[1]);
                if(r1 != r2) merge(id, sz, r1, r2);
            }
        }
        unordered_map<string, set<string>> m;
        for(auto & i:id) m[root(id, i.first)].insert(i.first);
        vector<vector<string>> ans;
        for(auto & i:m){
            vector<string> row;
            row.push_back(name[i.first]);
            for(auto & j:i.second) row.push_back(j);
            ans.push_back(row);
        }
        return ans;
    }
};