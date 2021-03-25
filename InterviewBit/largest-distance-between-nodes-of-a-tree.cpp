// https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/

int dfs(vector<vector<int>> & adjList, int cur, vector<bool> & visited){
    visited[cur] = 1;
    int res = 0;
    for(auto nbr:adjList[cur]){
        if(!visited[nbr]){
            res = max(res, 1+dfs(adjList, nbr, visited));
        }
    }
    visited[cur] = 0;
    return res;
}

void findLongest(vector<vector<int>> & adjList, int cur, vector<bool> & visited, int & last, int curLen, int & longest){
    
    if(curLen > longest){
        last = cur;
        longest = curLen;
    }
    
    visited[cur] = 1;
    for(auto nbr:adjList[cur]){
        if(!visited[nbr]){
            findLongest(adjList, nbr, visited, last, curLen+1, longest);
        }
    }
    visited[cur] = 0;
}

int Solution::solve(vector<int> &A) {
    int n = A.size(), root;
    if(n == 0 or n == 1) return 0;
    if(n == 2 or n == 3) return n-1;
    
    vector<vector<int>> adjList(n);
    
    for(int i=0; i<n; i++){
        if(A[i] == -1) continue;
        adjList[A[i]].push_back(i);
        adjList[i].push_back(A[i]);
    }
    
    vector<bool> visited(n, 0);
    int last = root, longest = 0;
    findLongest(adjList, root, visited, last, 0, longest);
    
    return dfs(adjList, last, visited);
}
