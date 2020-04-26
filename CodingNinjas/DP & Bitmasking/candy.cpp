// Candy
// Send Feedback
// Gary is a teacher at XYZ school. To reward his N students he bought a packet of N candies all with different flavours. But the problem is some students like certain flavour while some doesn't. Now Gary wants to know the number of ways he can distribute these N candies to his N students such that every student gets exactly one candy he likes.
// Input Format :
// Line 1 : An integer N (1<= N <= 16) denoting number of students and candies.
// Next N lines : N integers describing the preferences of one student. 1 at i'th (0 <= i < N) position denotes that this student likes i'th candy , 0 means he doesn't.
// Assume input to be 0-indexed based.
// Output Format :
// Return the number of ways Gary can distribute these N candies to his N students such that every student gets exactly one candy he likes.``
// Sample Input:
// 3
// 1 1 1
// 1 1 1
// 1 1 1
// Sample Output:
// 6

#include<bits/stdc++.h>
using namespace std;

long long helper(int ** like, int N, int p, int mask, int * dp){
    int ans = 0;
    if(p>=N){
        return 1;
    }
    if(dp[mask] != -1){
        return dp[mask];
    }
    for (int i = 0; i < N; i++)
    {
        if(!(mask&(1<<i)) && like[p][i]){
            ans += helper(like, N, p+1, mask|(1<<i), dp);
        }
    }
    dp[mask] = ans;
    return ans;
}

long long solve(int ** like,int N)
{
    int * dp = new int[1<<N];
    for (int i = 0; i < (1<<N); i++)
    {
        dp[i] = -1;
    }
    long long ans = helper(like, N, 0, 0, dp);
    delete [] dp;
    return ans;
}

int main(){
    int n;
    cin>>n;
    int ** like = new int*[n];
    for (int i = 0; i < n; i++)
    {
        like[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin>>like[i][j];
        }
    }
    long long ans = solve(like, n);
    cout<<ans<<endl;
    for (int i = 0; i < n; i++)
    {
        delete [] like[i];
    }
    delete [] like;
    return 0;
}