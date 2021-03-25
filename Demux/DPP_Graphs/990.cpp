// https://leetcode.com/problems/satisfiability-of-equality-equations/

// Method 1 (Union Find):

class Solution {
public:
    
    int root(int x, vector<int> & id){
        if(id[x] == x) return x;
        return id[x] = root(id[x], id);
    }
    
    void merge(int x, int y, vector<int> & id, vector<int> & sz){
        int xr = root(x, id), yr = root(y, id);
        if(sz[xr] > sz[yr]) swap(xr, yr);
        id[xr] = yr;
        sz[yr] += sz[xr];
    }
    
    bool equationsPossible(vector<string>& equations) {
        // UNION FIND
        
        vector<int> id(26), sz(26, 1);
        for(int i = 0; i<26; i++) id[i] = i;
        
        for(auto e:equations){
            if(e[1] == '=' and root(e[0]-'a', id) != root(e[3]-'a', id)) merge(e[0]-'a', e[3]-'a', id, sz);
        }
        for(auto e:equations){
            if(e[1] == '!' and root(e[0]-'a', id) == root(e[3]-'a', id)) return false;
        }
        return true;
    }
};