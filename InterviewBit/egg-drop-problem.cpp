// https://www.interviewbit.com/problems/egg-drop-problem/

// Attempt 1:

int helper(int eggCount, int h, vector<vector<int>> & dp){
    if(h <= 0) return 0;
    if(eggCount == 0) return dp[eggCount][h] = 1e5;
    if(dp[eggCount][h] != -1) return dp[eggCount][h];
    
    // int res = 1e5;
    // for(int k = 0; k<h; k++){
    //     res = min(res, 1+max(helper(eggCount-1, k, dp), helper(eggCount, h-k-1, dp)));
    // }
    
    // binary search optimization
    // FT, first T
    
    int lo = 0, hi = h-1, mid, h1, h2;
    while(lo<hi){
        mid = lo+(hi-lo)/2;
        h1 = helper(eggCount-1, mid, dp);       // inc function
        h2 = helper(eggCount, h-mid-1, dp);     // dec function
        if(h2>=h1){
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    int res;
    
    // h1 = helper(eggCount-1, lo, dp);       // inc function
    // h2 = helper(eggCount, h-lo-1, dp);     // dec function
    // if(h1>=h2) res = 1+max(helper(eggCount-1, lo, dp), helper(eggCount, h-lo-1, dp));
    // else res = 1+max(helper(eggCount-1, hi, dp), helper(eggCount, h-hi-1, dp));
    
    res = 1+min(max(helper(eggCount-1, lo, dp), helper(eggCount, h-lo-1, dp)), max(helper(eggCount-1, hi, dp), helper(eggCount, h-hi-1, dp)));
    
    return dp[eggCount][h] = res;
}

int Solution::solve(int A, int B) {
    vector<vector<int>> dp(A+1, vector<int>(B+2, -1));
    // dp[i][j] = min moves to find out C from j options with i eggs
    // we never drop from 0 as if we get a break after droping from 1, this case is covered
    return helper(A, B, dp);
}

// Method 1 (DP, O(A*B2), Failing for large test cases):

int helper(int eggCount, int h, vector<vector<int>> & dp){
    if(h <= 0) return 0;
    if(eggCount == 0) return dp[eggCount][h] = 1e5;
    if(dp[eggCount][h] != -1) return dp[eggCount][h];
    
    int res = 1e5;
    for(int k = 0; k<h; k++){
        res = min(res, 1+max(helper(eggCount-1, k, dp), helper(eggCount, h-k-1, dp)));
    }
    return dp[eggCount][h] = res;
}

int Solution::solve(int A, int B) {
    vector<vector<int>> dp(A+1, vector<int>(B+2, -1));
    // dp[i][j] = min moves to find out C from j options with i eggs
    // we never drop from 0 as if we get a break after droping from 1, this case is covered
    return helper(A, B, dp);
}
