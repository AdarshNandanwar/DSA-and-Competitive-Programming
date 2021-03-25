// https://www.interviewbit.com/problems/path-in-directed-graph/

// Method 1 (DFS, O(E+V)):

bool dfs(int A, vector<vector<int>> & adjList, int cur, vector<bool> & visited){
    if(cur == A-1) return 1;
    bool res = 0;
    for(auto nbr:adjList[cur]){
        if(!visited[nbr]){
            visited[nbr] = 1;
            res = res or dfs(A, adjList, nbr, visited);
        }
    }
    return res;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adjList(A);
    vector<bool> visited(A, 0);
    for(auto i:B) adjList[i[0]-1].push_back(i[1]-1);
    return dfs(A, adjList, 0, visited);
}
