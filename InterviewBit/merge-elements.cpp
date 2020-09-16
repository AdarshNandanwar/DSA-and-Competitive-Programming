// https://www.interviewbit.com/problems/merge-elements/

// Method 1 (DP, O(n2)):

pair<int, int> helper(vector<int> &A, int st, int end, vector<vector<pair<int, int>>> & dp){
    if(st == end) return {0, A[st]};
    if(dp[st][end].first != -1) return dp[st][end];
    int sum = 0, minCost = INT_MAX;
    for(int i = st; i<end; i++){
        // selecting the pair which we will merge in the last
        // merging number formed by [st..i] and [i..end]
        auto h1 = helper(A, st, i, dp);
        auto h2 = helper(A, i+1, end, dp);
        if(minCost > h1.first+h2.first+h1.second+h2.second){
            minCost = h1.first+h2.first+h1.second+h2.second;
            sum = h1.second+h2.second;
        }
    }
    return dp[st][end] = {minCost, sum};
}
 
int Solution::solve(vector<int> &A) {
    int n = A.size();
    // dp[i][j] = {cost of merging [i..j], sum of [i..j]}
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, -1}));
    return helper(A, 0, n-1, dp).first;
}