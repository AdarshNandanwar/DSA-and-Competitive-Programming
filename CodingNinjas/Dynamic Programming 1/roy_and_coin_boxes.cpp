// Roy and Coin Boxes
// Send Feedback
// Roy has N coin boxes numbered from 1 to N.
// Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
// He does this for M number of days.

// After M days, Roy has a query: How many coin boxes have atleast X coins.
// He has Q such queries.
// Input
// First line contains N - number of coin boxes.
// Second line contains M - number of days. Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
// Each of next Q lines contain a single integer X.a
// Output
// For each query output the result in a new line.
// Constraints
// 1 ≤ N ≤ 1000000

// 1 ≤ M ≤ 1000000

// 1 ≤ L ≤ R ≤ N

// 1 ≤ Q ≤ 1000000

// 1 ≤ X ≤ N
// Sample Input
// 7
// 4
// 1 3
// 2 5
// 1 2
// 5 6
// 4
// 1
// 7
// 4
// 2
// Sample Output
// 6
// 0
// 0
// 4

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, s, e;
    cin>>n>>m;
    int * start = new int[n]();
    int * end = new int[n]();
    for (int i = 0; i < m; i++)
    {
        cin>>s>>e;
        start[s-1]++;
        end[e-1]++;
    }
    
    int * box = new int[n]();
    long long * coin = new long long[m+1]();
    box[0] = start[0];
    coin[box[0]]++;
    for (int i = 1; i < n; i++)
    {
        box[i] = box[i-1] + start[i] - end[i-1];
        coin[box[i]]++;
    }    
    for (int i = m-1; i >= 0; i--)
    {
        coin[i] = coin[i+1] + coin[i];
    }
    int q, x;
    cin>>q;
    while(q--){
        cin>>x;
        if(x > m){
            cout<<0<<endl;
        } else {
            cout<<coin[x]<<endl;
        }
    }
    delete [] start;
    delete [] end;
    delete [] box;
    delete [] coin;
    return 0;
}