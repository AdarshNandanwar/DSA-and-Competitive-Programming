#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll X[100001];
ll Y[100001];
ll n, m;

ll solve_base_x(ll index){
    ll count = 0;
    for (ll i = 0; i < index; i++)
    {
        for (ll j = index; j < n; j++)
        {
            if(binary_search(Y, Y+m, sqrt((-1)*X[i]*X[j]))){ 
                count++;
                // cout<<X[i]<<" "<<X[j]<<" "<<sqrt((-1)*X[i]*X[j])<<endl;
            }
            if(binary_search(Y, Y+m, (-1)*sqrt((-1)*X[i]*X[j]))){ 
                count++;
                // cout<<X[i]<<" "<<X[j]<<" "<<(-1)*sqrt((-1)*X[i]*X[j])<<endl;
            }
        }
    }
    return count;
}

ll solve_base_y(ll index){
    ll count = 0;
    for (ll i = 0; i < index; i++)
    {
        for (ll j = index; j < m; j++)
        {
            if(binary_search(X, X+n, sqrt((-1)*Y[i]*Y[j]))){ 
                count++;
                // cout<<Y[i]<<" "<<Y[j]<<" "<<sqrt((-1)*Y[i]*Y[j])<<endl;
            }
            if(binary_search(X, X+n, (-1)*sqrt((-1)*Y[i]*Y[j]))){ 
                count++;
                // cout<<Y[i]<<" "<<Y[j]<<" "<<(-1)*sqrt((-1)*Y[i]*Y[j])<<endl;
            }
        }
    }
    return count;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        bool has_zero = false;
        for (ll i = 0; i < n; i++)
        {
            cin>>X[i];
            if(!X[i]){
                has_zero = true;
                i--;
                n--;
            }
        }
        for (ll i = 0; i < m; i++)
        {
            cin>>Y[i];
            if(!Y[i]){
                has_zero = true;
                i--;
                m--;
            }
        }


        sort(X, X+n);        
        sort(Y, Y+m);        

        ll ans = 0;
        ll zero_index;
        for (ll i = 0; i < n; i++)
        {
            if(X[i]>0){
                zero_index = i;
                break;
            }
        }
        ans += solve_base_x(zero_index);
        for (ll i = 0; i < m; i++)
        {
            if(Y[i]>0){
                zero_index = i;
                break;
            }
        }
        // cout<<endl;
        ans += solve_base_y(zero_index);
        if(has_zero){
            ans += (n*m);
        }
        
        cout<<ans<<endl;

    }
}