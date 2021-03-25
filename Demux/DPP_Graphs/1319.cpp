// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

// Method 1 (Union Find by Rank and Path Compression, (O(logV))):

class Solution {
public:
    
    int root(int a, vector<int> & id){
        if(id[a] == a) return a;
        return id[a] = root(id[a], id);
    }
    
    void merge(int a, int b, vector<int> & id, vector<int> & sz){
        int ar = root(a, id), br = root(b, id);
        if(sz[ar] > sz[br]) swap(ar, br);
        id[ar] = br;
        sz[br] += sz[ar];
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> id(n), sz(n, 1);
        for(int i = 0; i<n; i++) id[i] = i;
        int extraWires = 0, components = n;
        for(auto i:connections){
            if(root(i[0], id) == root(i[1], id)){
                extraWires++;
            } else {
                merge(i[0], i[1], id, sz);
                components--;
            }
        }
        return extraWires>=components-1?components-1:-1;
    }
};