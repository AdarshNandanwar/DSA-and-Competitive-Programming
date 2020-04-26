// Subset Sum - Problem
// Send Feedback
// Given a set of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.

// Input Format
// First line contains a single integer n (1<=n<=1000)
// Second line contains n space separated integers (1<=a[i]<=1000)
// Last line contains a single positive integer k (1<=k<=1000)
// Output Format
// Output Yes if there exists a subset whose sum is k, else output No.
// Sample Input
// 3
// 1 2 3
// 4
// Sample Output
// YES

#include <bits/stdc++.h>
using namespace std;

int solve(int * arr, int n, int sum, int ** dp){
    if(n == 0){
        if(sum == 0){
            return 1;
        } else {
            return 0;
        }
    }
    if(sum == 0){
        return 1;
    }
    if(sum < 0){
        return 0;
    }
    if(dp[n][sum] != -1){
        return dp[n][sum];
    }
    int option1 = solve(arr+1, n-1, sum-arr[0], dp);
    int option2 = solve(arr+1, n-1, sum, dp);
    int ans = max(option1, option2);
    dp[n][sum] = ans;
    return ans;
}

int main()
{
    int n, k;
    cin>>n;
    int * arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cin>>k;
    int ** dp = new int*[n+1];
    for (int i = 0; i < n+1; i++)
    {
        dp[i] = new int[k+1];
        for (int j = 0; j < k+1; j++)
        {
            dp[i][j] = -1;
        }   
    }
    cout<<(solve(arr, n, k, dp)?"Yes":"No")<<endl;
    for (int i = 0; i < n+1; i++)
    {
        delete [] dp[i];
    }
    delete [] dp;
    delete [] arr;
    return 0;
}