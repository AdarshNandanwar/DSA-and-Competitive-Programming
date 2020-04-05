#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

void solve(){

    deque<ll> q;
    cin>>n;
    for (ll i = 0; i < n; i++)
    {
        ll temp;
        cin>>temp;
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
                if(ans <= abs(((q.front()-start) / len))){
                    ans = abs(((q.front()-start) / len));
                    k = start+((q.front()-start) / len);
                }
            } else {
                if(ans <= abs(((q.front()-start) / len))+1){
                    ans = abs(((q.front()-start) / len))+1;
                    k = start+((q.front()-start) / len);
                }
            }
            len = 1;
            start = q.front();
        } else {
            len++;
        }
        q.pop_front();
    }
    cout<<ans<<" "<<k<<endl;
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