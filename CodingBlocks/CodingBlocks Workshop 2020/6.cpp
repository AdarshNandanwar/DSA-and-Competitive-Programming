#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
	ll k;
	cin>>k;
	string s;
	cin>>s;
	ll len = s.length(), xc = 0, yc = 0;

	vector<ll> xind, yind;

	for(ll i = 0; i< len; i++){
		if(s[i] == 'x'){
			xind.push_back(i);
		} else {
			yind.push_back(i);
		}
	}

	xc = xind.size();
	yc = yind.size();

	if(k >= xc || k >= yc){
		cout<<len<<endl;
		return 0;
	}

	ll md = -1, start = -1, end = -1;
	
	for(ll i = 0; (i+k-1)<xc; i++){
		start = i;
		end = i+k-1;
		if(start == 0){
			if(end == xc-1){
				md = max(md, len);
			} else {
				md = max(md, xind[end+1]);
			}
		} else {
			if(end == xc-1){
				md = max(md, len - xind[start-1]-1);
			} else {
				md = max(md, xind[end+1] - xind[start-1] -1);
			}
		}
		
	}
	for(ll i = 0; (i+k-1)<yc; i++){
		start = i;
		end = i+k-1;
		if(start == 0){
			if(end == yc-1){
				md = max(md, len);
			} else {
				md = max(md, yind[end+1]);
			}
		} else {
			if(end == yc-1){
				md = max(md, len - yind[start-1] - 1);
			} else {
				md = max(md, yind[end+1] - yind[start-1] -1);
			}
		}
	}

	cout<<md<<endl;

	return 0;
}