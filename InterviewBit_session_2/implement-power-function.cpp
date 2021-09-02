// https://www.interviewbit.com/problems/implement-power-function/

// Method 1 (Binary Exponentiation):

// https://cp-algorithms.com/algebra/binary-exp.html

int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(x == 0) return 0;
    if(n == 0) return 1;
    if(n == 1) return (d+x%d)%d;
    
    int r = Solution::pow(x, n>>1, d);
    if(n&1) return (d+((((long)r*r)%d)*x)%d)%d;
    else return (d+(((long)r*r)%d))%d;
}

// Method 2 (Recursion, DP):

×
int helper(int x, int n, int d, unordered_map<int, int> & dp){
    if(x == 0) return 0;
    if(n == 0) return 1;
    if(n == 1) return (d+x%d)%d;
    
    if(dp.count(n)) return dp[n];
    long r1 = helper(x, n/2, d, dp);
    long r2 = helper(x, n-n/2, d, dp);
    dp[n] = (d+(r1*r2)%d)%d;
    return dp[n];
}
 
int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    unordered_map<int, int> dp;
    return helper(x, n, d, dp);
}