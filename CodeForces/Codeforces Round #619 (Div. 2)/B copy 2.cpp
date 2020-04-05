#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

void solve(){

    deque<ll> q;
    cin>>n;
    ll * arr = new ll[n]();
    for (ll i = 0; i < n; i++)
    {
        ll temp;
        cin>>temp;
        arr[i] = temp;
        q.push_back(temp);
    }
    while(!q.empty() && q.front() == -1){
        q.pop_front();
    }
    while(!q.empty() && q.back() == -1){
        q.pop_back();
    }
    if(q.empty()){
        cout<<"0 0"<<endl;
        return;
    }
    
    ll ans = 0, k = 0, len = 1;
    vector<ll> v;
    ll start = -1;
    while(!q.empty()){
        // cout<<"len"<<len<<endl;
        if(q.front() != -1){
            // cout<<q.front()<<endl;
            if(start == -1){
                // cout<<"first"<<q.front()<<endl;
                start = q.front();
                q.pop_front();
                continue;
            }
            if((q.front()-start) % len == 0){
                // if(ans <= abs(((q.front()-start) / len))){
                //     ans = abs(((q.front()-start) / len));
                //     k = start+((q.front()-start) / len);
                // }
                v.push_back(abs(((q.front()-start) / len)));
            } else {
                // if(ans <= abs(((q.front()-start) / len))+1){
                //     ans = abs(((q.front()-start) / len))+1;
                //     k = start+((q.front()-start) / len);
                // }
                v.push_back(abs(((q.front()-start) / len))+1);
            }
            len = 1;
            start = q.front();
        } else {
            len++;
        }
        q.pop_front();
    }
    
    vector<ll>::iterator itr;
    ll sum = 0;
    for(itr = v.begin(); itr != v.end(); itr++){
        sum += (*itr);
    }
    if(v.size() == 0){
        cout<<"0 0\n";
        return;
    }
    sum /= v.size();
    ll max_diff = 0;
    for (ll i = 0; i < n; i++)
    {
        if(arr[i] != -1){
            max_diff = max(max_diff, abs(arr[i] - sum));
        }
    }
    if(arr[0] == -1){
        arr[0] = max_diff;
    }
    for (ll i = 1; i < n; i++)
    {
        if(arr[i] == -1){
            arr[i] = max_diff;
        }
        sum = max(sum,abs(arr[i]-arr[i-1]));
    }
    
    cout<<sum<<" "<<max_diff<<endl;
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