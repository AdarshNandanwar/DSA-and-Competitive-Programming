#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n , m;
    cin>>n>>m;
    if(n == 0 or m == 0) {
        cout<<0<<endl;
        return;
    }
    vector<vector<ll>> A(n, vector<ll>(m));
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<m; j++){
            cin>>A[i][j];
        }
    }
    
    for(ll i = 0; i<n; i++){
        if(A[i][0] == 0){
            for(ll j = 0; j<m; j++){
                A[i][j] = !A[i][j];
            }
        }
    }
    for(ll j = 0; j<m; j++){
        ll count = 0;
        for(ll i = 0; i<n; i++){
            count += A[i][j];
        }
        if(count < (n+1)/2){
            for(ll i = 0; i<n; i++){
                A[i][j] = !A[i][j];
            }
        }
    }
    
    ll res = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            res += (A[i][j]<<(m-1-j));
        }
    }
    cout<<res<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Prll output to STDOUT */   
    ll t;
    cin>>t;
    while(t--) solve();
    return 0;
}
