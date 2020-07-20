// https://practice.geeksforgeeks.org/problems/number-of-subsequences-in-a-string-divisible-by-n/0

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int helper(string & s, int & n,  int & m, int start, int rem, vector<vector<int>> & dp){
    if(start >= n){
        return rem == 0;
    }
    
    if(dp[start][rem] != -1) return dp[start][rem];
    
    int res = 0;
    res = (res+helper(s, n, m, start+1, (rem*10+(s[start]-'0'))%m, dp))%MOD;
    res = (res+helper(s, n, m, start+1, rem, dp))%MOD;
    
    return dp[start][rem] = res;
}

int main() {
	//code
	
	int t, n, m;
	string s;
	cin>>t;
	while(t--){
	    cin>>n>>m;
	    cin>>s;
	    vector<vector<int>> dp(n, vector<int>(m, -1));
	    // subtract the empty subsequence
	    int res = helper(s, n, m, 0, 0, dp);
	    cout<<(res==0?to_string(10e9+6):to_string(res-1))<<endl;
	}
	
	return 0;
}