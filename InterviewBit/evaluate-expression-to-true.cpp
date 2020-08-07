// https://www.interviewbit.com/problems/evaluate-expression-to-true/

#define MOD 1003
pair<int, int> helper(string & A, int st, int end, vector<vector<pair<int, int>>> & dp){
    if(st == end) return A[st] == 'T' ? make_pair(1, 0) : make_pair(0, 1);
    if(dp[st][end] != make_pair(-1, -1)) return dp[st][end];
    pair<int, int> res = {0,0};
    for(int i = st+1; i<end; i+=2){
        auto l = helper(A, st, i-1, dp), r = helper(A, i+1, end, dp);
        if(A[i] == '|'){
            res.first = (res.first + (l.first*r.first)%MOD + (l.first*r.second)%MOD + (l.second*r.first)%MOD)%MOD;
            res.second = (res.second + (l.second*r.second)%MOD)%MOD;
        } else if(A[i] == '&'){
            res.first = (res.first + (l.first*r.first)%MOD)%MOD;
            res.second = (res.second + (l.second*r.second)%MOD + (l.second*r.first)%MOD + (l.first*r.second)%MOD)%MOD;
        } else {
            res.first = (res.first + (l.first*r.second)%MOD + (l.second*r.first)%MOD)%MOD;
            res.second = (res.second + (l.first*r.first)%MOD + (l.second*r.second)%MOD)%MOD;
        }
    }
    return dp[st][end] = res;
}

int Solution::cnttrue(string A) {
    int n = A.length();
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1,-1}));
    return helper(A, 0, n-1, dp).first;
}
