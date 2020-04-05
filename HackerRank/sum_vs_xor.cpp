#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n, zero_count = 0, ans = 1;
	cin>>n;
	while(n){
		if((n&1) == 0){
			zero_count++;
		}
		n /= 2;
	}
	ans *= ((ll)1<<zero_count);
	cout<<ans<<endl;
	return 0;
}