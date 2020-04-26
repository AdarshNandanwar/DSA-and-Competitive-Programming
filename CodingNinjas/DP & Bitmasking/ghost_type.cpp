// Ghost Type
// Send Feedback
// Gengar has got an integer N. Now using his ghostly powers, he can create the permutation from 1 to N of this given number.
// Since, he's a special kind of Poke'mon, so he thinks he deserves special permutations. He wants to find the total number of special permutations of length N, consisting of the integers from 1 to N
// .

// A permutation is called special if it satisfies following condition:
// If Ap & Aq == Ap, then p < q, where p and q are two distinct indices of permutation and A is the permutation itself. "&" denotes the bitwise and operation.
// Help Gengar in finding the number of such permutations.
// Input format:
// The only line of input will consist of a single integer N denoting the length of the permutation.
// Output format:
// Output the total number of special permutations of length N
// .

// Constraints:
// 1 ≤ N ≤ 20

// SAMPLE INPUT
// 4

// SAMPLE OUTPUT
// 8

// Explanation
// All the special permutations of length 4 are: 1 2 3 4

// 1 2 4 3

// 1 4 2 3

// 2 1 3 4

// 2 1 4 3

// 2 4 1 3

// 4 1 2 3

// 4 2 1 3

#include <iostream>
using namespace std;
typedef long long ll;

long long helper(ll n, ll mask, ll * dp){
    ll ans = 0;
    if(mask ==(1<<n)-1){
        return 1;
    }
    if(dp[mask] != -1){
        return dp[mask];
    }
    
    for (ll i = 0; i < n; i++)
    {
        if(!(mask&(1<<i))){
            for (ll j = 0; j < n; j++)
            {
                if((mask&(1<<j)) && (((n-i)&(n-j)) == (n-i))){
                    return 0;
                }
            }
            ans += helper(n, mask|(1<<i), dp);
        }
    }
    dp[mask] = ans;
    return ans;
}

ll solve(ll n)
{
    ll * dp = new ll[1<<n];
    for (ll i = 0; i < (1<<n); i++)
    {
        dp[i] = -1;
    }
    long long ans = helper(n, 0, dp);
    delete [] dp;
    return ans;
}

int main()
{
    ll n;
    cin>>n;
    ll ans = solve(n);
    cout<<ans<<endl;
    return 0;
}