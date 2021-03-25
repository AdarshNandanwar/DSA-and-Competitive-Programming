#include<bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
	cin>>t;

	while(t--) {
		int n;
		cin>>n;

		int a[n];
		for(int i=0; i<n; i++) {
			cin>>a[i];
		}

		unordered_map<int, int>  hash;
		int l, r;

		int pre=0;
		for(int i=0; i<n; i++) {
			pre = (pre + a[i]) % n;

			if(pre == 0) {
				r = i;
				l = -1;
				break;
			}

			else if(hash.find(pre) != hash.end()) {
				r = i;
				l = hash[pre];

				//cout<<i<<" "<<pre<<" "<<l<<" "<<r<<"\n";
				break;
			}

			else {
				hash[pre] = i;
			}

		}

		cout<<r-l<<"\n";
		for(int i=l+1; i<=r; i++) {
			cout<<i+1<<" ";
		}
		cout<<"\n";
	}

}