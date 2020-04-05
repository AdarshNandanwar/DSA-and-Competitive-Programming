#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

list<pair<ll, ll>> edges;

ll getSizeDFS(ll n, bool visited[101]){
    if(visited[n]) return 0;
    ll size = 1;
    list<pair<ll, ll>>::iterator itr;
    for(itr = edges.begin(); itr != edges.end(); itr++){
        pair<ll, ll> temp = *itr;
        if(temp.first == n){
            visited[n] = true;
            size += getSizeDFS(temp.second, visited);
        } else if(temp.second == n){
            visited[n] = true;
            size += getSizeDFS(temp.first, visited);
        }
    }
    return size;
}

bool isEvenSize(ll n){
    bool visited[101];
    for (ll i = 0; i < 101; i++)
    {
        visited[i] = false;
    }
    ll size = getSizeDFS(n, visited);
    // cout<<size<<endl;
    return (size%2 == 0);
}

int main(){
    ll n, e;
    cin>>n>>e;

    for (ll i = 0; i < e; i++)
    {
        ll n1, n2;
        cin>>n1>>n2;
        n1--;n2--;
        edges.push_back(make_pair(n1, n2));
    }
    
    ll count = 0;
    list<pair<ll, ll>>::iterator itr;
    for(itr = edges.begin(); itr != edges.end(); itr++){
        pair<ll, ll> temp;
        temp = *itr;
        // cout<<"edge: "<<temp.first+1<<" "<<temp.second+1<<endl;
        itr = edges.erase(itr);
        if(isEvenSize(temp.first) && isEvenSize(temp.second)){
            count++;
            // cout<<"count: "<<count<<endl;
            continue;
        }
        itr = edges.insert(itr, temp);
    }
    cout<<count<<endl;

    return 0;
}