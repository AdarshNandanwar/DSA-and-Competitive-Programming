#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
# define M 1000003

ll solve(ll n, ll k, ll p, ll *** dp){

	if(dp[n][k][p] != -1){
		return dp[n][k][p];
	}
	ll ans;
	if(p == 0){
		if(n-k <= 1){
			return 0;
		}
		ans = (solve(n-1, k, 0, dp)%M + solve(n-1, k, 1, dp)%M)%M;

	} else {
		if(k <= 0){
			return 1;
		}
		ans = (solve(n-1, k, 0, dp)%M + solve(n-1, k-1, 1, dp)%M)%M;
	}
	dp[n][k][p] = ans;
	return ans;
}

int main() {

	ll t;
	cin>>t;
	while(t--){
		ll n, k;
		cin>>n>>k;
		ll *** dp = new ll**[n+1];
		for(ll i = 0; i <n+1; i++){
			dp[i] = new ll*[k+1];
			for(ll j = 0; j<k+1; j++){
				dp[i][j] = new ll[2];
				for(ll ij = 0; ij < 2; ij++){
					dp[i][j][ij] = -1;
				}
			}
		}
		cout<<(solve(n, k, 0, dp)%M+solve(n, k, 1, dp)%M)%M<<endl;
	}
	return 0;
}