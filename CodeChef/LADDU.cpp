#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll t;
	cin>>t;
	while(t--){
		ll k, laddu = 0;
		cin>>k;
		string origin;
		cin>>origin;
		while(k--){
			string s;
			cin>>s;
			if(s == "CONTEST_WON"){
				ll rank;
				cin>>rank;
				laddu += 300;
				laddu += max((ll)0, 20-rank);
			} else if(s == "TOP_CONTRIBUTOR"){
				laddu += 300;
			} else if(s == "BUG_FOUND"){
				ll severity;
				cin>>severity;
				laddu += severity;
			} else {
				laddu += 50;
			}
		}
		if(origin == "INDIAN"){
			cout<<laddu/200<<endl;
		} else {
			cout<<laddu/400<<endl;
		}
	}

	return 0;
}