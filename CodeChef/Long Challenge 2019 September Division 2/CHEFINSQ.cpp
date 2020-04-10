#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll helper(int * arr, int n, int k, int sum, ll *** dp){
    if(sum==0 && k==0){
        return 1;
    }
    if(sum<=0 || k<=0 || n<=0){
        return 0;
    }
    if(dp[n][k][sum]!=-1){
        return dp[n][k][sum];
    }
    ll ans = 0;
    ans += helper(arr+1, n-1, k-1, sum-arr[0], dp);
    ans += helper(arr+1, n-1, k, sum, dp);
    dp[n][k][sum] = ans;
    return ans;
}

ll calulateInterestingSubsequenceCount(int * arr, int n, int k, int sum){
    //make dp array
    ll *** dp = new ll**[n+1];
    for (int i = 0; i < n+1; i++)
    {
        dp[i] = new ll*[k+1];
        for (int j = 0; j < k+1; j++)
        {
            dp[i][j] = new ll[sum+1];
            for (int l = 0; l < sum+1; l++)
            {
                dp[i][j][l] = -1;
            }
        }
    }
    
    ll ans = helper(arr, n, k, sum, dp);
    //delete dp array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            delete [] dp[i][j];
        }
        delete [] dp[i];
    }
    delete [] dp;    
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int * arr = new int[n];
        int * sorted_arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin>>temp;
            arr[i] = temp;
            sorted_arr[i] = temp;
        }
        
        sort(sorted_arr, sorted_arr+n);
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum+=sorted_arr[i];
        }
        delete [] sorted_arr;

        ll ans = calulateInterestingSubsequenceCount(arr, n, k, sum);
        cout<<ans<<endl;
        delete [] arr;
    }
    return 0;
}