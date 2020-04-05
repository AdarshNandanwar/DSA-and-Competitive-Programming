ll ith_fib_term(ll n, ll * dp){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if (dp[n]!=-1){
        return dp[n];
    }
    int ans;
    if(n%2){
        int k = (n+1)/2;
        ans = ith_fib_term(k, dp)*ith_fib_term(k, dp) + ith_fib_term(k-1, dp)*ith_fib_term(k-1, dp);
    } else {
        int k = n/2;
        ans = (2*ith_fib_term(k-1, dp)+ith_fib_term(k, dp))*ith_fib_term(k, dp);
    }
    dp[n] = ans;
    return ans;
}