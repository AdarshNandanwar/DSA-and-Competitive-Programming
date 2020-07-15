// https://leetcode.com/problems/accounts-merge/

// Method 1 (Union Find):

class Solution {
public:
    
    string root(string x, unordered_map<string, string> & id){
        if(id[x] == x) return x;
        return id[x] = root(id[x], id);
    }
    
    void merge(string x, string y, unordered_map<string, string> & id, unordered_map<string, string> & sz){
        string xr = root(x, id), yr = root(y, id);
        if(xr == yr) return;
        if(sz[xr] > sz[yr]) swap(xr, yr);
        id[xr] = yr;
        sz[yr] += sz[xr];
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // Union Find
        
        unordered_map<string, string> id, sz, name;
        unordered_map<string, set<string>> email;
        for(auto a:accounts) {
            for(int i=1; i<a.size(); i++){
                name[a[i]] = a[0];
                id[a[i]] = a[i];
                sz[a[i]] = 1;
            }
        }
        
        for(auto a:accounts){
            for(int i=2; i<a.size(); i++){
                merge(a[i-1], a[i], id, sz);
            }
        }
        
        for(auto & [i, j]:id){
            email[root(i, id)].insert(i);
        }
        
        vector<vector<string>> ans;
        for(auto [i, j]:email){
            vector<string> entry;
            entry.push_back(name[i]);
            for(auto e:j) entry.push_back(e);
            ans.push_back(entry);
        }
        return ans;
    }
};