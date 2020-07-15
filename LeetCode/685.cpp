// https://leetcode.com/problems/redundant-connection-ii/

class Solution {
public:
    
    int root(int x, vector<int> & id){
        if(id[x] == x) return x;
        return id[x] = root(id[x], id);
    }
    
    void merge(int x, int y, vector<int> & id, vector<int> & sz){
        if(sz[x] > sz[y]) swap(x, y);
        id[x] = y;
        sz[y] += sz[x];
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size(), deg2V = -1;
        vector<vector<int>> inDeg(n);
        vector<int> res;
        for(auto & e:edges){
            e[0]--;
            e[1]--;
            inDeg[e[1]].push_back(e[0]);
            if(inDeg[e[1]].size() == 2) deg2V = e[1];
        }
        
        int numComp = n;
        vector<int> id(n), sz(n, 1);
        for(int i = 0; i<n; i++) id[i] = i;
        
        if(deg2V != -1){
            // inDeg pattern:  1211011      i.e 2 parents
            vector<int> a = {inDeg[deg2V][0], deg2V}, b = {inDeg[deg2V][1], deg2V};
            // union find algorithm
            for(auto cur:edges){
                if(cur[0] == b[0] and cur[1] == b[1]) continue;
                int r0 = root(cur[0], id), r1 = root(cur[1], id);
                if(r0 == r1) continue;;
                merge(r0, r1, id, sz);
                numComp--;
            }
            res = numComp == 1 ? b : a;
        } else {
            // inDeg pattern:  1111111      i.e. cycle
            // union find algorithm
            for(auto cur:edges){
                int r0 = root(cur[0], id), r1 = root(cur[1], id);
                if(r0 == r1){
                    res = cur;
                    break;
                }
                merge(r0, r1, id, sz);
            }
        }
        return {res[0]+1, res[1]+1};
    }
};