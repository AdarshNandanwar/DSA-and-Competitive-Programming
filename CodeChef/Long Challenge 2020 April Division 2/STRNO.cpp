#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll countPrimeFactors(ll n) 
{ 
	ll count = 0;
	while (n%2 == 0) 
	{ 
		count++;
		n = n/2; 
	}
	for (ll i = 3; i <= sqrt(n); i = i+2) 
	{ 
		while (n%i == 0) 
		{ 
			count++;
			n = n/i; 
		} 
	}

	if (n > 2) 
		count++;
	return count;
}

int main(){
	ll t;
	cin>>t;
	while(t--){
		ll X, K;
		cin>>X>>K;
		if(countPrimeFactors(X)>=K)
			cout<<1<<endl;
		else
			cout<<0<<endl;
	}
	return 0; 
} 
