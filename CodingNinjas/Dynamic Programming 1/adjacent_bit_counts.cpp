// Adjacent Bit Counts
// Send Feedback
// For a string of n bits x1,x2,x3,...,Xn the adjacent bit count of the string (AdjBC(x)) is given by
// X1*X2 + X2*X3 + X3*X4 + ... + Xn-1 * Xn
// which counts the number of times a 1 bit is adjacent to another 1 bit. For example:
// AdjBC(011101101) = 3
// AdjBC(111101101) = 4
// AdjBC(010101010) = 0
// Write a program which takes as input integers n and k and returns the number of bit strings x of n bits (out of 2ⁿ) that satisfy AdjBC(x) = k. For example, for 5 bit strings, there are 6 ways of getting AdjBC(x) = 2:
// 11100, 01110, 00111, 10111, 11101, 11011
// Input
// The first line of input contains a single integer P, (1 ≤ P ≤ 1000), which is the number of data sets that follow. Each data set is a single line that contains the data set number, followed by a space, followed by a decimal integer giving the number (n) of bits in the bit strings, followed by a single space, followed by a decimal integer (k) giving the desired adjacent bit count. The number of bits (n) will not be greater than 100.
// Output
// For each data set there is one line of output. It contains the data set number followed by a single space, followed by the number of n-bit strings with adjacent bit count equal to k. As answer can be very large print your answer modulo 10^9+7.
// Sample Input
// 10
// 1 5 2
// 2 20 8
// 3 30 17
// 4 40 24
// 5 50 37
// 6 60 52
// 7 70 59
// 8 80 73
// 9 90 84
// 10 100 90
// Sample Output
// 1 6
// 2 63426
// 3 1861225
// 4 168212501
// 5 44874764
// 6 160916
// 7 22937308
// 8 99167
// 9 15476
// 10 23076518

#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k, int prev, int *** dp){
    if(n == 0){
        if(k == 0){
            return 1;
        } else {
            return 0;
        }
    }
    if(k<0){
        return 0;
    }
    if(dp[n][k][prev] != -1){
        return dp[n][k][prev];
    }
    int ans = 0;
    if(prev == 1){
        ans += solve(n-1, k-1, 1, dp)%1000000007;
        ans += solve(n-1, k, 0, dp)%1000000007;
    } else {
        ans += solve(n-1, k, 0, dp)%1000000007;
        ans += solve(n-1, k, 1, dp)%1000000007;
    }
    dp[n][k][prev] = ans;
    return ans%1000000007;
}

int bit_count(int n, int k){
    int *** dp = new int**[n+1];
    for (int i = 0; i < n+1; i++)
    {
        dp[i] = new int*[k+1];
        for (int j = 0; j < k+1; j++)
        {
            dp[i][j] = new int[2];
            for (int l = 0; l < 2; l++)
            {
                dp[i][j][l] = -1;
            } 
        }
    }
    int ans = solve(n, k, 0, dp);
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < k+1; j++)
        {
            delete [] dp[i][j];
        }
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}

int main()
{
    int t, n, k, temp;
    cin>>t;
    for (int i = 1; i < t+1; i++)
    {
        cin>>temp>>n>>k;
        cout<<i<<" "<<bit_count(n, k)<<endl;
    }    
    return 0;
}