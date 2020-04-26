#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

ll pow_mod(ll x, ll y, ll mod){
    ll ans = 1;
    for (ll i = 0; i < y; i++)
    {
        ans = ((ans%mod)*(x%mod))%mod;
    }
    return ans;
}

ll pow_factorial(ll n, ll mod){
    if(n >= mod){
        return 0;
    }
    int ans = 1;
    for (ll i = 1; i <= n; i++)
    {
        ans = ((ans%mod)*(i%mod))%mod;
    }
    return ans;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll N;
        cin>>N;
        ll n = 2*N;
        vector<ll> arr(n);
        map<ll, ll> m, ans;
        set<ll> elements;
        for (ll i = 0; i < n; i++)
        {
            cin>>arr[i];
            m[arr[i]]++;
        }
        
        sort(arr.begin(), arr.end());
        for (ll i = 0; i < n; i++)
        {
            if(m[arr[i]]%2 == 0 && m[arr[i]] >= 2){
                vector<ll> temp = arr;
                temp.erase(lower_bound(temp.begin(), temp.end(), arr[i]));
                temp.erase(lower_bound(temp.begin(), temp.end(), arr[i]));

                set<pair<ll, ll>> s;
                map<pair<ll, ll>, ll> m_factorial;

                ll equal_count = 0;

                bool not_found = false;

                while(!temp.empty()){
                    if(binary_search(temp.begin()+1, temp.end(), arr[i]-temp[0])){
                        ll a = temp[0];
                        ll b = arr[i]-temp[0];
                        temp.erase(temp.begin());
                        temp.erase(lower_bound(temp.begin(), temp.end(), b));
                        pair<ll, ll> p = make_pair(a, b);
                        if(a == b){
                            equal_count++;
                        }
                        s.insert(p);
                        m_factorial[p]++;
                    } else {
                        not_found = true;
                        break;
                    }
                }
                // cout<<not_found<<endl;

                // set<pair<ll, ll>>::iterator itr1;
                // for(itr1 = s.begin(); itr1!=s.end(); itr1++){
                //     cout<<(*itr1).first<<", "<<(*itr1).second<<" Count: "<<m_factorial[(*itr1)]<<endl;
                // }
                // cout<<"Equal "<<equal_count<<endl;
                


                if(not_found){
                    continue;
                } else {
                    ll term1 = pow_mod(2, N-1-equal_count, M);
                    ll term2 = pow_factorial(N-1, M);
                    // cout<<term1<<" "<<term2<<endl;
                    set<pair<ll, ll>>::iterator itr;
                    for(itr = s.begin(); itr!=s.end(); itr++){
                        term2 = ((term2%M) / (pow_factorial(m_factorial[*itr], M)%M)%M);
                    }
                    // cout<<term1<<" "<<term2<<endl;
                    ll term = ((term1%M)*(term2%M))%M;
                    ans[arr[i]] = term;
                    elements.insert(arr[i]);
                }
            }
        }
        
        ll final_ans = 0;
        set<ll>::iterator itr_element;
        for(itr_element = elements.begin(); itr_element != elements.end(); itr_element++){
            // cout<<*itr_element<<" "<<ans[*itr_element]<<endl;
            final_ans = ((final_ans%M)+(ans[*itr_element]%M))%M;
        }
        cout<<final_ans<<endl;


    }
    return 0;
}