#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll,ll> operator + (pair<ll, ll> p1, pair<ll, ll> p2){
    return make_pair(p1.first+p2.first, p1.second+ p2.second);
}

bool isValid(pair<ll, ll> p, ll n, ll m){
    return (0<=p.first && p.first<n && 0<=p.second && p.second<m);
}

int main(){
    ll n, m;
    cin>>n>>m;
    ll ** arr = new ll*[n];
    for (ll i = 0; i < n; i++)
    {
        arr[i] = new ll[m];
        for (ll j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
    }
    

    queue<pair<ll, ll>> q;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if(arr[i][j] == 2){
                q.push({i, j});
                // cout<<i<<", "<<j<<endl;
            }
        }
    }

    q.push({-1, -1});
    // cout<<-1<<", "<<-1<<endl;
    ll time = 0;

    while(q.size()!=1){
        pair<ll, ll> p = q.front();
        if(p.first == -1 && p.second == -1){
            q.pop();
            q.push(p);
            // cout<<p.first<<", "<<p.second<<endl;
            time++;
            continue;
        }
        vector<pair<ll, ll>> v = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<pair<ll, ll>>::iterator itr;
        for(itr = v.begin(); itr!= v.end(); itr++){
            pair<ll, ll> temp = p+*itr;
            if(isValid(temp, n, m) && arr[temp.first][temp.second] == 1){
                arr[temp.first][temp.second] = 2;
                q.push(temp);
                // cout<<temp.first<<", "<<temp.second<<endl;
            }
        }
        q.pop();
        
    }
    
    cout<<time<<endl;

    for (ll i = 0; i < n; i++)
    {
        delete [] arr[i];
    }
    delete [] arr;

    return 0;
}