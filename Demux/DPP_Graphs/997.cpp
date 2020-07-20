// https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(N-1>trust.size()) return -1;
        vector<int> in_deg(N, 0);
        vector<bool> trusts(N);
        for(auto t:trust){
            in_deg[t[1]-1]++;
            trusts[t[0]-1] = true;
        }
        for(int i = 0; i<N; i++){
            if(trusts[i] == false and in_deg[i] == N-1) return i+1;
        }
        return -1;
    }
};