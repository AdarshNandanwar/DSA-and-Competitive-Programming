// https://leetcode.com/problems/satisfiability-of-equality-equations/

// Method 1 (Union Find with Rank and Path Compression, O(n)):

class Solution {
    int root(int x, vector<int> & id){
        if(id[x] == x){
            return x;
        }
        return id[x] = root(id[x], id);
    }
    void merge(int u, int v, vector<int> & id , vector<int> & sz){
        u = root(u, id);
        v = root(v, id);
        if(u == v){
            return;
        }
        if(sz[u] > sz[v]){
            swap(u, v);
        }
        id[u] = v;
        sz[v] += sz[u];
    }
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> id(26), sz(26, 1);
        for(int i=0; i<26; i++){
            id[i] = i;
        }
        for(auto &equation:equations){
            int u = equation[0]-'a';
            int v = equation[3]-'a';
            if(equation[1] == '='){
                merge(u, v, id, sz);
            }
        }
        for(auto &equation:equations){
            int u = equation[0]-'a';
            int v = equation[3]-'a';
            if(equation[1] == '!' and root(u, id) == root(v, id)){
                return false;
            }
        }
        return true;
    }
};