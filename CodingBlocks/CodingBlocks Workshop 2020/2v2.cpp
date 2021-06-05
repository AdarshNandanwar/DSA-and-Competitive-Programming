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

	bool ans = false;

	for(ll i = 1; i<n; i++){
		bool temp = true;
		for(int j = 1; j < i; j++){
			if(arr[j] >= arr[j-1]){
				temp = false;
				// if(i == 4) cout<<"j1 = "<<j<<endl;
			}
		}
		for(ll j = i+1; j < n; j++){
			if(arr[j] <= arr[j-1]){
				temp = false;
				// if(i == 4) cout<<"j2 = "<<j<<endl;
			}
		}
		if(temp){
			ans = true;
		}
	}

	cout<<(ans?"true\n":"false\n");

	delete [] arr;

	return 0;
}