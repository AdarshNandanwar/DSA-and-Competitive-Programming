#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(ll n, ll k, ll p){

	ll ans;
	if(p == 0){
		if(n-k <= 1){
			return 0;
		}
		ans = solve(n-1, k);

	} else {
		if(k <= 0){
			return 1;
		}
		ans = solve(n-1, k, 0) + solve(n-1, k-1, 1);
	}
	return ans;
}

ll solve(ll n, ll k){
	return (solve(n, k, 0)+solve(n, k, 1));
}

int main() {

	ll t;
	cin>>t;
	while(t--){
		ll n, k;
		cin>>n>>k;
		cout<<solve(n, k)<<endl;
	}
	return 0;
}