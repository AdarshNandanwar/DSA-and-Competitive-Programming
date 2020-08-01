// https://www.interviewbit.com/problems/word-ladder-i/

int Solution::solve(string A, string B, vector<string> &C) {
    C.push_back(A);
    C.push_back(B);
    unordered_map<string, vector<string>> adjList;
    
    int n = C.size(), diff;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            diff = 0;
            for(int k = 0; k<A.length(); k++) diff += (C[i][k] != C[j][k]);
            if(diff == 1){
                adjList[C[i]].push_back(C[j]);
                adjList[C[j]].push_back(C[i]);
            } 
        }
    }
    
    // BFS
    
    unordered_set<string> visited;
    queue<string> q;
    q.push(A);
    visited.insert(A);
    int count = 1;
    while(!q.empty()){
        int sz = q.size();
        for(int i = 0; i<sz; i++){
            auto cur = q.front();
            q.pop();
            if(cur == B) return count;
            for(auto nbr:adjList[cur]){
                if(!visited.count(nbr)){
                    visited.insert(nbr);
                    q.push(nbr);
                }
            }
        }
        count++;
    }
    return 0;
}
