// https://www.hackerrank.com/contests/placements-2021-mock-1/challenges/ishan-and-his-swaps

// Ishan was getting bored over the summer at his home so he decided to make a game with binary numbers.

// He has a binary grid with  rows and  columns and he can pick up 1 row or column at a time and swap all elements of that row/column. Hence for all elements  of the chosen row/column,  becomes .

// He has a lot of time over the summer, and hence he can do this operation any number of times.

// After that, he interprets each row as a binary number, and wants to know the maximum sum of all  rows he can achieve.

// Input Format

// First line contains , the number of test cases. For each test case, the first line contains  and  denoting the rows and columns of the matrix.

//  lines follow, each line contains  spaced integers either 0 or 1.

// Constraints




// Output Format

// Output a single integer denoting the maximum sum that you can get.

// Sample Input 0

// 2
// 3 3
// 1 0 0
// 1 1 0
// 1 1 0
// 3 4
// 0 1 0 1
// 0 1 1 0
// 0 0 1 0
// Sample Output 0

// 19
// 38
// Explanation 0

// For the first grid, if Ishan swaps the last column, the rows become 1 0 1, 1 1 1, 1 1 1.

// Hence sum of each row = 5 + 7 + 7 = 19, which is the maximum that can be achieved.

// Method 1 (Math logic):

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;


ll n;

void solve(){

    ll r, c, a;
    cin>>r>>c;
    vector<ll> ones(c, 0);
    for(ll i = 0; i<r; i++){
        bool flip = 0;
        for(ll j = 0; j<c; j++){
            cin>>a;
            if(j == 0 and a == 0) flip = 1;
            if(flip) a = 1-a;
            ones[j] += a;
        }
    }
    ll res = 0;
    for(ll i = 0; i<c; i++){
        ones[i] = max(ones[i], r-ones[i]);
        res = res+ones[i]*((ll)1<<(c-i-1));
    }
    cout<<res<<endl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

// Method 2 (Graph, TLE):

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void dfs(string s, unordered_set<string> & visited, ll & res, const int & r, const int & c){
    if(visited.count(s)) return;
    visited.insert(s);
    ll val = 0;
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            val += ((s[c*i+j]-'0')*(1<<(c-j-1)));
        }
    }
    // if(val > res){
    //     cout<<s<<endl;
    // }
    res = max(res, val);
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            s[c*i+j] = 2*'0'+1-s[c*i+j];
        }
        dfs(s, visited, res, r, c);
        for(int j = 0; j<c; j++){
            s[c*i+j] = 2*'0'+1-s[c*i+j];
        }
    }
    for(int i = 0; i<c; i++){
        for(int j = 0; j<r; j++){
            s[c*j+i] = 2*'0'+1-s[c*j+i];
        }
        dfs(s, visited, res, r, c);
        for(int j = 0; j<r; j++){
            s[c*j+i] = 2*'0'+1-s[c*j+i];
        }
    }
}

ll n;

void solve(){

    ll r, c;
    cin>>r>>c;
    string s = string(r*c, 'a');
    for(ll i = 0; i<r; i++){
        for(ll j = 0; j<c; j++){
            cin>>s[i*c+j];
        }
    }
    // cout<<s<<endl;
    unordered_set<string> visited;
    ll res = 0;
    dfs(s, visited, res, r, c);
    cout<<res<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}