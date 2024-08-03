// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/

// Method 1 (Union Find with Rank and Path Compression, O(ElogV)):

class Solution {
    int getRoot(int x, vector<int>& root){
        if(x == root[x]){
            return x;
        }
        return root[x] = getRoot(root[x], root);
    }

    void merge(int r1, int r2, vector<int>& root, vector<int>& sz){
        r1 = getRoot(r1, root);
        r2 = getRoot(r2, root);
        if(sz[r1] > sz[r2]){
            swap(r1, r2);
        }
        sz[r2] += sz[r1];
        root[r1] = r2;
    }

    int unionFind(int components, const vector<vector<int>>& edges, vector<int>& root, vector<int>& sz){
        for(auto& edge:edges){
            int r1 = getRoot(edge[0], root);
            int r2 = getRoot(edge[1], root);
            if(r1 == r2){
                continue;
            }

            merge(r1, r2, root, sz);

            components--;
        }
        
        return components;
    }
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // Separate edges
        vector<vector<int>> commonEdges;
        vector<vector<int>> aliceEdges;
        vector<vector<int>> bobEdges;
        for(auto& edge:edges){
            if(edge[0] == 1){
                aliceEdges.push_back({edge[1]-1, edge[2]-1});
            } else if(edge[0] == 2){
                bobEdges.push_back({edge[1]-1, edge[2]-1});
            } else if(edge[0] == 3){
                commonEdges.push_back({edge[1]-1, edge[2]-1});
            }
        }

        // Group all components using common edges (Greedy)
        vector<int> sz(n, 1);
        vector<int> root(n);
        for(int i=0; i<n; i++){
            root[i] = i;
        }

        int commonComponents = unionFind(n, commonEdges, root, sz);

        int commonEdgesCount = n - commonComponents;
        int aliceEdgesCount = commonComponents - 1;
        int bobEdgesCount = commonComponents - 1;
        int edgesNeeded = commonEdgesCount + aliceEdgesCount + bobEdgesCount;
        int edgesDeleted = edges.size() - edgesNeeded;

        // Check if Alice can fully traverse
        vector<int> aliceSz(sz);
        vector<int> aliceRoot(root);
        int aliceComponents = unionFind(commonComponents, aliceEdges, aliceRoot, aliceSz);
        if(aliceComponents > 1){
            return -1;
        }

        // Check if Bob can fully traverse
        vector<int> bobSz(sz);
        vector<int> bobRoot(root);
        int bobComponents = unionFind(commonComponents, bobEdges, bobRoot, bobSz);
        if(bobComponents > 1){
            return -1;
        }

        return edgesDeleted;
    }
};
