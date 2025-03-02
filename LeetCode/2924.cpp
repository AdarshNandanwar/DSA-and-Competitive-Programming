// https://leetcode.com/problems/find-champion-ii/

// Method 1 (Topological Sort Logic, O(E+V)):

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n);
        for(auto & edge:edges){
            inDegree[edge[1]]++;
        }

        int champion = -1;
        for(int i=0; i<n; i++){
            if(inDegree[i]){
                continue;
            }
            if(champion == -1){
                champion = i;
            } else {
                return -1;
            }
        }

        return champion;
    }
};
