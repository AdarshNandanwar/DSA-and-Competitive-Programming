// https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/

// Method 1 (Topological Sort, O(E)):

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    vector<vector<int>> adjList(A);
    vector<int> inDeg(A, 0);
    int n = B.size();
    for(int i=0; i<n; i++){
        adjList[B[i]-1].push_back(C[i]-1);
        inDeg[C[i]-1]++;
    }
    queue<int> q;
    for(int i = 0; i<A; i++){
        if(inDeg[i] == 0) q.push(i);
    }
    int done = 0;
    while(!q.empty()){
        int cur = q.front();
        done++;
        q.pop();
        for(auto nbr:adjList[cur]){
            inDeg[nbr]--;
            if(inDeg[nbr] == 0) q.push(nbr);
        }
    }
    return done == A;
}
