// Knapsnack - Problem
// Send Feedback
// A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
// Space complexity should be O(n).
// Input Format :
// Line 1 : N i.e. number of items
// Line 2 : N Integers i.e. weights of items separated by space
// Line 3 : N Integers i.e. values of items separated by space
// Line 4 : Integer W i.e. maximum weight thief can carry
// Output Format :
// Line 1 : Maximum value V
// Constraints
// 1 <= N <= 10^4
// 1<= wi <= 100
// 1 <= vi <= 100
// Sample Input 1 :
// 4
// 1 2 4 5
// 5 4 8 6
// 5
// Sample Output :
// 13

#include<bits/stdc++.h>
using namespace std;

int solve(int * w, int * v, int n, int W, int ** dp){

    for (int i = 0; i < W+1; i++)
    {
        dp[0][i] = 0;
    }
    int flag = 0;
    for (int i = 1; i < n+1; i++)
    {
        flag = flag^1;
        for (int j = 0; j < W+1; j++)
        {
            if(j >= w[i-1]){
                dp[flag][j] = max(v[i-1] + dp[flag^1][j-w[i-1]], dp[flag^1][j]);
            } else {
                dp[flag][j] = dp[flag^1][j];
            }
        }
    }
    
    int ans = dp[flag][W];
    return ans;
}

int knapsack(int* weights, int* values, int n, int maxWeight){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */

    int ** dp = new int*[2];
    for (int i = 0; i < 2; i++)
    {
        dp[i] = new int[maxWeight+1];
        for (int j = 0; j < maxWeight+1; j++)
        {
            dp[i][j] = -1;
        }
    }
    int ans = solve(weights, values, n, maxWeight, dp);
    for (int i = 0; i < 2; i++)
    {
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}

int main(){
    int n;
    cin>>n;
    int * w = new int[n];
    int * v = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>w[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int W;
    cin>>W;
    cout<<knapsack(w, v, n, W)<<endl;
    delete [] w;
    delete [] v;
    return 0;
}