// https://www.interviewbit.com/problems/ways-to-color-a-3xn-board/

// Method 1 (DP, Maths, O(n)):

#define MOD 1000000007
int Solution::solve(int A) {
    if(A == 0) return 1;
    // dp[i][0] = number of ways to construct valid arrays in [0..i] with patern made of exactly 2 numbers in the ith index
    // dp[i][1] = number of ways to construct valid arrays in [0..i] with patern made of exactly 3 numbers in the ith index
    vector<vector<long>> dp(A, vector<long>(2));
    // base case
    dp[0][0] = 4*3;
    dp[0][1] = 4*3*2;
    for(int i = 1; i<A; i++){
        dp[i][0] = ((7*dp[i-1][0])%MOD + (5*dp[i-1][1])%MOD)%MOD;
        dp[i][1] = ((10*dp[i-1][0])%MOD + (11*dp[i-1][1])%MOD)%MOD;
    }
    return (dp[A-1][0]+dp[A-1][1])%MOD;
}

// Method 2 (DP, O(n*64*64), TLE):

#define MOD 1000000007

int Solution::solve(int A) {
    if(A == 0) return 1;
    vector<vector<int>> patterns;
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            if(i == j) continue;
            for(int k = 0; k<4; k++){
                if(k == j) continue;
                patterns.push_back({i, j, k});
            }
        }
    }
    // dp[x][i][j][k] = number of ways to construct valid arrays in [0..x] with {i, j, k} as the pattern at xth index
    vector<vector<vector<vector<int>>>> dp(A, vector<vector<vector<int>>>(4, vector<vector<int>>(4, vector<int>(4, 0))));
    // base case
    for(auto prev:patterns){
        dp[0][prev[0]][prev[1]][prev[2]] = 1;
    }
    for(int x = 1; x<A; x++){
        for(auto cur:patterns){
            for(auto prev:patterns){
                if(prev[0] == cur[0] or prev[1] == cur[1] or prev[2] == cur[2]) continue;
                dp[x][cur[0]][cur[1]][cur[2]] = (dp[x][cur[0]][cur[1]][cur[2]]+dp[x-1][prev[0]][prev[1]][prev[2]])%MOD;
            }
        }
    }
    int res = 0;
    for(auto cur:patterns) res = (res+dp[A-1][cur[0]][cur[1]][cur[2]])%MOD;
    return res;
}
