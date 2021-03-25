// https://www.hackerrank.com/contests/intern-2020-bpgc/challenges/flip-elements

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<int> v(n);
        
        for(int i = 0; i<n; i++) cin>>v[i];
        
        ll sum = 0;
        for(auto i:v) sum += i;
        
        ll target = sum/2;
        
        
        // dp[i][j] = min selection to make sum equal to j in [i..n-1]
        vector<vector<int>> dp(n+1, vector<int>(target+1, n+1));
        
        
        for(int i = 0; i<n+1; i++) dp[i][0] = 0;
        
        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<=target; j++){
                dp[i][j] = dp[i+1][j];
                if(j-v[i] >= 0) dp[i][j] = min(dp[i][j], 1+dp[i+1][j-v[i]]);
            }
        }
        
        for(int i = target; i>=0; i--){
            if(dp[0][i] <= n){
                cout<<dp[0][i]<<endl;
                break;
            }
        }
        
    
    }
    
    return 0;
}
