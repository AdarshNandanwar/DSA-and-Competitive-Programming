#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int helper(int * arr, int n, map<int,bool> m, int k, int ** dp){
    if(n == 0 || k == 0){
        return 1;
    }
    if(dp[n][k] != -1){
        return dp[n][k];
    }
    int ans = 0;
    if(m[arr[0]]){
        ans = helper(arr+1, n-1, m, k, dp);
    } else {
        m[arr[0]] = true;
        ans = (ans + helper(arr+1, n-1, m, k-1, dp))%1000000007;
        m[arr[0]] = false;
        ans = (ans + helper(arr+1, n-1, m, k, dp))%1000000007;    
    }
    dp[n][k] = ans;
    return ans;
}

int main(){
    int n, k;
    cin>>n>>k;
    int * arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    map<int,bool> m;        //default value false
    int ** dp = new int*[n+1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[k+1];
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = -1;
        }
    }
    
    ll ans = helper(arr, n, m, k, dp);
    cout<<ans<<endl;
    for (int i = 0; i <= n; i++)
    {
        delete [] dp[i];
    }
    delete [] dp;
    return 0;
}

// int main(){
//     int n, k;
//     cin>>n>>k;
//     int * arr = new int[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin>>arr[i];
//     }
//     map<int, int> m;
//     for (int i = 0; i < n; i++)
//     {
//         m[arr[i]]++;
//     }
//     int ans = 1;
//     for (int i = 2; i <= 8000; i++)
//     {
//         ans = ans * (m[i]+1);
//     }
//     cout<<ans<<endl;
//     return 0;
// }