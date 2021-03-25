// https://www.interviewbit.com/problems/snake-ladder-problem/

// Method 1 (BFS, O(V+E)):

int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    vector<int> next(101);
    for(int i = 1; i<=100; i++) next[i] = i;
    for(auto i:A) next[i[0]] = i[1];
    for(auto i:B) next[i[0]] = i[1];
    vector<bool> visited(101, 0);
    int res = 0;
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        int sz = q.size();
        for(int t = 0; t<sz; t++){
            auto cur = q.front();
            q.pop();
            if(cur == 100) return res;
            for(int i = 1; i<=6; i++){
                if(!visited[next[cur+i]]) q.push(next[cur+i]);
                visited[next[cur+i]] = 1;
            }
        }
        res++;
    }
    return -1;
}

// Method 2 (DFS, O(V+E)):

int helper(vector<int> & next, int pos, vector<int> & dp){
    if(pos == 100) return 0;
    if(dp[pos] >= 0) return dp[pos];
    if(dp[pos] == -2) return 101;
    dp[pos] = -2;
    int res = 101;
    for(int i = 1; i<=6 and pos+i<=100; i++) res = min(res, 1+helper(next, next[pos+i], dp));
    return dp[pos] = res;
}

int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    vector<int> next(101);
    for(int i = 1; i<=100; i++) next[i] = i;
    for(auto i:A) next[i[0]] = i[1];
    for(auto i:B) next[i[0]] = i[1];
    vector<int> dp(101, -1);    // -2 = visited
    int res = helper(next, 1, dp);
    return res < 100 ? res : -1;
}
