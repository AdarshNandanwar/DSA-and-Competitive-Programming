// https://leetcode.com/problems/sequence-reconstruction/

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        
        // edge cases
        if(seqs.size() == 0) return false;
        bool allZero = true;
        for(auto i:seqs){
            if(i.size() != 0){
                allZero = false;
                break;
            }
        }
        if(allZero) return false;
        
        vector<unordered_set<int>> g(n);
        vector<int> inDeg(n, 0);
        for(int i=0; i<seqs.size(); i++){
            for(int j = seqs[i].size()-1; j>=0; j--){
                if(seqs[i][j] <= 0 or seqs[i][j] > n) return false;
                if(j == seqs[i].size()-1) continue;
                int k = j+1;
                if(g[seqs[i][j]-1].find(seqs[i][k]-1) == g[seqs[i][j]-1].end()){
                    g[seqs[i][j]-1].insert(seqs[i][k]-1);
                    inDeg[seqs[i][k]-1]++;
                }
            }
        }
        
        // TOPOLOGICAL SORT
        
        queue<int> q;
        
        for(int i = 0; i<n; i++){
            if(inDeg[i] == 0) q.push(i);
        }
        
        int pos = 0;
        
        while(!q.empty()){
            if(q.size() > 1) return false;
            int cur = q.front();
            q.pop();
            if(org[pos++]-1 != cur) return false;
            for(auto nbr:g[cur]){
                inDeg[nbr]--;
                if(inDeg[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        
        return pos == n;
    }
};