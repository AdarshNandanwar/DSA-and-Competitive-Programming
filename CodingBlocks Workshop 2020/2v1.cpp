#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin>>n;
	ll * arr = new ll[n];
	for(ll i = 0; i < n; i++){
		cin>>arr[i];
	}

	bool inc = false, ans = true;

	for(ll i = 1; i< n; i++){
		if(arr[i] > arr[i-1]){
			inc = true;
		}
		if( arr[i] < arr[i-1] && inc == true){
			ans = false;
		}
	}

	cout<<(ans?"true\n":"false\n");

	delete [] arr;

	return 0;
}