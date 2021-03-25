// Question:

// Longest Common Prefix II
// Defining substring
// For a string P with characters P1, P2 ,…, Pq, let us denote by P[i, j] the substring Pi, Pi+1 ,…, Pj.

// Defining longest common prefix
// LCP(S1, S2 ,…, SK), is defined as largest possible integer j such that S1[1, j] = S2[1, j] = … = SK[1, j].

// You are given an array of N strings, A1, A2 ,…, AN and an integer K. Count how many indices (i, j) exist such that 1 ≤ i ≤ j ≤ N and LCP(Ai, Ai+1 ,…, Aj) ≥ K. Print required answer modulo 109+7.

// Note that K does not exceed the length of any of the N strings. K <= min(len(A_i)) for all i

// For example,

// A = ["ab", "ac", "bc"] and K=1.

// LCP(A[1, 1]) = LCP(A[2, 2]) = LCP(A[3, 3]) = 2
// LCP(A[1, 2]) = LCP("ab", "ac") = 1
// LCP(A[1, 3]) = LCP("ab", "ac", "bc") = 0
// LCP(A[2, 3]) = LCP("ac", "bc") = 0

// So, answer is 4.
// Return your answer % MOD = 1000000007

// Constraints
// 1 ≤ Sum of length of all strings ≤ 5*105
// Strings consist of small alphabets only.




// Attempt 2 (TLE):

#define MOD 1000000007

int Solution::LCPrefix(vector<string> &A, int B) {
    long n = A.size();
    if(n == 0) return 0;
    int res = n%MOD, h, k;    
    
    vector<vector<int>> dp(2, vector<int>(n, -1));
    
    for(int i = n-1; i>=0; i--){
        for(int j = i+1; j<n; j++){
            h =  (i+1 == j ? A[j].length() : dp[(i+1)%2][j]);
            for(k = 0; k<A[i].length() and k<h; k++) if(A[i][k] != A[i+1][k]) break;
            dp[i%2][j] = k%MOD;
            res = (res + (dp[i%2][j]>=B))%MOD;
        }
    }
    return res;
}

// Attempt 1 (MLE):

#define MOD 1000000007

int helper(vector<string> &A, int B, int st, int end, vector<vector<int>> & dp){
    if(st == end) return dp[st][end] = A[st].length()%MOD;
    if(dp[st][end] != -1) return dp[st][end];
    int h = helper(A, B, st+1, end, dp), i;
    for(i = 0; i<A[st].length() and i<h; i++) if(A[st][i] != A[st+1][i]) break;
    return dp[st][end] = i%MOD;
}

int Solution::LCPrefix(vector<string> &A, int B) {
    long n = A.size();
    if(n == 0) return 0;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int res = 0, h;
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            h =  helper(A, B, i, j, dp);
            res = (res + (h>=B))%MOD;
        }
    }
    // for(auto i:dp){for(auto j:i) cout<<j<<" "; cout<<endl;}
    return res;
}




// Try 1 (Don't know if the logic is correct):

#define MOD 1000000007

int Solution::LCPrefix(vector<string> &A, int B) {
    long n = A.size(), maxLen = 0;
    if(n == 0) return 0;
    for(auto i:A) maxLen = max(maxLen, (long)i.length());
    // dp[i][j] = length of array ending at i index with LCP equals to j+1
    vector<vector<int>> dp(n, vector<int>(maxLen+1, 0));
    long res = 1;
    // base case
    for(int j = 0; j<A[0].length(); j++){
        dp[0][j] = 1;
        if(j+1>=B) res = (res+dp[0][j])%MOD;
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<A[i].length(); j++){
            if(A[i][j] == A[i-1][j]){
                dp[i][j] = 1+dp[i-1][j];
                if(j+1>=B) res = (res+dp[i][j])%MOD;
            } else {
                break;
            }
        }
    }
    for(auto i:dp){ for(auto j:i) cout<<j<<" "; cout<<endl;}
    return res;
}
