// https://www.interviewbit.com/problems/path-with-good-nodes/

// Method 1 (DFS, O(E+V)):

int helper(vector<int> & A, vector<vector<int>> & adjList, int C, int cur, int prev) {
    bool isLeaf = 1;
    if(A[cur]){
        if(C == 0) return 0;
        else C--;
    }
    int res = 0;
    for(auto nbr:adjList[cur]){
        if(nbr == prev) continue;
        isLeaf = 0;
        res += helper(A, adjList, C, nbr, cur);
    }
    return isLeaf + res;
}

int Solution::solve(vector<int> &A, vector<vector<int>> &B, int C) {
    int n = A.size();
    vector<vector<int>> adjList(n);
    for(auto i:B){
        adjList[i[0]-1].push_back(i[1]-1);
        adjList[i[1]-1].push_back(i[0]-1);
    }
    return helper(A, adjList, C, 0, -1);
}
