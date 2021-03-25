#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;


vector<ll> getPeaks(vector<ll> & v){
    ll n = v.size();
    vector<ll> peaks;
    for(int i = 0; i<n-1; i++){
        while(i<n-1 && v[i] > v[i+1]){
            i++;
        }
        while(i<n-1 && v[i] < v[i+1]){
            i++;
        }
        if(i != n-1){
            peaks.push_back(i);
        }
    }
    return peaks;
}

void solve(){

    cin>>n;
    ll k;
    cin>>k;
    vector<ll> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }

    vector<ll> temp = getPeaks(v);
    vector<bool> peaks(n, false);
    for(int i = 0; i<temp.size(); i++){
        peaks[temp[i]] = true;
    }
    
    ll count = 0;
    ll max_count = 0;
    ll start_ind = 0;

    k-=2;

    for(int i = 1; i<=k; i++){
        // cout<<i<<" : ";
        if(peaks[i]){
            count++;
        }
        if(count>max_count){
            max_count = count;
            start_ind = 0;
            // cout<<max_count+1<<" "<<start_ind+1<<endl;
        }
    }
    for(int i = k+1; i<n-1; i++){
        // cout<<i<<" : ";
        if(peaks[i]){
            count++;
        }
        if(peaks[i-k]){
            count--;
        }
        if(count>max_count){
            max_count = count;
            start_ind = i-k;
            // cout<<max_count+1<<" "<<start_ind+1<<endl;
        }
    }
    // cout<<"final: "<<max_count+1<<" "<<start_ind+1<<endl;
    cout<<max_count+1<<" "<<start_ind+1<<endl;
    return;
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}