#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include<unordered_map>
#define ll long long
using namespace std;

bool comp(pair<pair<ll,ll>,ll> p1,pair<pair<ll,ll>,ll> p2){
    if(p1.first.first>p2.first.first){
        return false;
    }
    else if(p1.first.first<p2.first.first){
        return true;
    }
    else{
        if(p1.first.second>p2.first.second){
            return true;
        }
        else{
            return false;
        }
    }
}


int main(){

	ll t;
	cin>>t;

	for(ll test=0;test<t;test++){
		vector< pair <pair<ll,ll> ,ll > >  v;
		ll n;
		cin>>n;

		for(ll i=0;i<n;i++){
			ll left,right,speed;
			cin>>left>>right>>speed;
			v.push_back(make_pair(make_pair(left,right),speed));
		}

		sort(v.begin(),v.end(),comp);

		// for(int i=0;i<n;i++){
		//  	cout<<"left"<<v[i].fir st.first<<" right:"<<v[i].first.second<<" speed"<<v[i].second<<endl;
		// }

		ll start=0;
		ll end=0;
		ll flag=0;

		unordered_map<ll,ll> m;

		while(start<n){
			if(v[start].first.first<=v[end].first.second){
				m[v[start].second]++;
				if(m[v[start].second]>2){
					flag=1;
					cout<<"NO\n";
					break;
				}
				start++;
			}
			else{
				m[v[end].second]--;
				end++;
			}
		}

		if(flag==0){
			cout<<"YES\n";
		}

	}
	return 0;
}