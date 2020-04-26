#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, ll * dp){
    if(n == 0){
        return 1;
    } else if(n==1){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    ll ans = 0;
    for (int i = 1; i < n+1; i++)
    {
        int temp = (int)(solve(i-1, dp) * solve(n-i, dp)) % 1000000007;
        ans = ((ans + temp) % 1000000007);
    }
    dp[n] = ans % 1000000007;
    return ans % 1000000007;
}

int countBST( int n)
{
  /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
    ll * dp = new ll[n+1];
    for (int i = 0; i < n+1; i++)
    {
        dp[i] = -1;
    }
    int ans = solve(n, dp);
    delete [] dp;
    return ans;
}

int main(){

    int n;
    cin>>n;
    cout<<countBST(n)<<endl;
    return 0;
}