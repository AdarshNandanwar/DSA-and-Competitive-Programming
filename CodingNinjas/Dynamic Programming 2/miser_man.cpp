// Miser Man
// Send Feedback
// Jack is a wise and miser man. Always tries to save his money.
// One day, he wants to go from city A to city B. Between A and B, there are N number of cities(including B and excluding A) and in each city there are M buses numbered from 1 to M. And the fare of each bus is different. Means for all N*M busses, fare (K) may be different or same. Now Jack has to go from city A to city B following these conditions:
// 1. At every city, he has to change the bus.
// 2. And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.
// You are to help Jack to go from A to B by spending the minimum amount of money.
// N, M, K <= 100.
// Input
// Line 1:    N M

// Line 2:    NxM Grid

// Each row lists the fares the M busses to go form the current city to the next city.
// Output
// Single Line containing the minimum amount of fare that Jack has to give.
// Sample Input
// 5 5
// 1  3  1  2  6
// 10 2  5  4  15
// 10 9  6  7  1
// 2  7  1  5  3
// 8  2  6  1  9
// Sample Output
// 10

#include <bits/stdc++.h>
using namespace std;

int solve(int ** arr, int r, int c, int ** dp){
    for (int i = 0; i < c; i++)
    {
        dp[r-1][i] = 0;
    }
    for (int i = r-2; i >= 0; i--)
    {
        for (int j = 0; j < c; j++)
        {
            if(j==0){
                dp[i][j] = min(dp[i+1][j] + arr[i+1][j], dp[i+1][j+1] + arr[i+1][j+1]);
            } else if (j == c-1) {
                dp[i][j] = min(dp[i+1][j] + arr[i+1][j], dp[i+1][j-1] + arr[i+1][j-1]);
            } else {
                dp[i][j] = min(dp[i+1][j] + arr[i+1][j], min(dp[i+1][j+1] + arr[i+1][j+1], dp[i+1][j-1] + arr[i+1][j-1]));
            }
        }        
    }
    int min_cost = INT_MAX;
    for (int i = 0; i < c; i++)
    {
        min_cost = min(min_cost, dp[0][i] + arr[0][i]);
    }
    return min_cost;    
}

int main()
{
    int n, m;
    cin>>n>>m;
    int ** arr = new int*[n];
    int ** dp = new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        dp[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
            dp[i][j] = -1;
        }
    }
    
    cout<<solve(arr, n, m, dp)<<endl;;

    for (int i = 0; i < n; i++)
    {
        delete [] dp[i];
        delete [] arr[i];
    }
    delete [] arr;
    delete [] dp;
    return 0;
}