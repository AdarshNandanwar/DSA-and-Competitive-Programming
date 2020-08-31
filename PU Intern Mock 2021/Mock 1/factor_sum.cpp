// https://www.hackerrank.com/contests/intern-2020-bpgc/challenges/factor-sum/problem

// Method 1 (Sieve of Eratosthenes, O(n*n)):

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> makeSieve(ll n){
    vector<ll> sieve(n+1, 1);
    for(ll i = 2; i<=n; i++){
        for(ll j = i; j<=n; j+=i){
            sieve[j] += i;
        }
    }
    return sieve;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll q;
    cin>>q;
    vector<ll> queries(q);
    for(ll i = 0; i<q; i++) cin>>queries[i];
    ll m = *max_element(queries.begin(), queries.end());
    auto sieve = makeSieve(m);
    for(auto i:queries) cout<<sieve[i]<<endl;
    return 0;
}

// Method 2 (Brute Force, O(q*n), TLE):

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll helper(int n, unordered_map<ll, ll> & dp){
    if(n == 1) return 1;
    if(dp.count(n)) return dp[n];
    ll res = 0;
    for(int i = 1; i*i<=n; i++) if(n%i == 0) res += (i+(i*i == n ? 0 : n/i));
    return dp[n] = res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll q, n;
    cin>>q;
    
    unordered_map<ll, ll> dp;
    for(int i = 0; i<q; i++){
        cin>>n;
        cout<<helper(n, dp)<<endl;
    }
    return 0;
}