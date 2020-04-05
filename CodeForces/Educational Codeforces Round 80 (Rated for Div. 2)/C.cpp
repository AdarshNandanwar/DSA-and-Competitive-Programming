#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007


ll solve_inc(ll n, ll m, ll ** dpi){
    
    if(n < 0){
        return 0;
    }
    if(m <= 0){
        return 1;
    }
    
    if(dpi[n][m] != -1){
        return dpi[n][m];
    }

    dpi[n][m] = (solve_inc(n-1, m, dpi) + solve_inc(n, m-1, dpi))%M;
    return dpi[n][m];
}

ll solve_dec(ll n, ll m, ll ** dpd){

    if(n < 0 || m < 0){
        return 0;
    }
    if(m == 0 && n == 0){
        return 1;
    }


    if(dpd[n][m] != -1){
        return dpd[n][m];
    }

    dpd[n][m] = (solve_dec(n-1, m, dpd) + solve_dec(n, m-1, dpd))%M;
    return dpd[n][m];
}

int main(){

    ll n, m;
    cin>>n>>m;
    

    ll ** dpi = new ll*[n+1];
    ll ** dpd = new ll*[n+1];
    for (ll i = 0; i < n+1; i++)
    {
        dpi[i] = new ll[m+1];
        dpd[i] = new ll[m+1];
        for (ll j = 0; j < m+1; j++)
        {
            dpi[i][j] = dpd[i][j] = -1;
        }
    }
    
    ll ans = 0;

    for (ll i = 1; i <= n; i++)
    {
        ll a_count = solve_dec(n-i, m, dpd);
        ll b_count = solve_inc(i-1, m-1, dpi);

        ans = ((ans + (a_count*b_count)%M)%M);
    }
    cout<<ans<<endl;


    for (ll i = 0; i < n+1; i++)
    {
        delete [] dpi[i];
        delete [] dpd[i];
    }
    delete [] dpi;
    delete [] dpd;

    return 0;
}