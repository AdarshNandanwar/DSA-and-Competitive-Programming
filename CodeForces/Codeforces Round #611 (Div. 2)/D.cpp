#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, m;
    cin>>n>>m;
    ll * arr = new ll[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n);
    ll last_pos = arr[n-1];

    queue<ll> q;
    map<ll, ll> visited;
    for (ll i = 0; i < n; i++)
    {
        q.push(arr[i]);
        visited[arr[i]] = 1;
    }

    ll count = 0, radius = 1, sum = 0;
    vector<ll> person;
    while(count < m){
        ll pos = q.front();
        if(!visited[pos-radius]){
            person.push_back(pos-radius);
            count++;
            sum += (radius);
            visited[pos-radius] = 1;
        }
        if(!visited[pos+radius]){
            person.push_back(pos+radius);
            count++;
            sum += (radius);
            visited[pos+radius] = 1;
        }
        if(pos == last_pos){
            radius++;
        }
        q.pop();
        q.push(pos);
    }
    cout<<sum<<endl;
    vector<ll>::iterator itr;
    for (itr = person.begin(); itr != person.end(); itr++){
        cout<<*itr<<" ";
    }cout<<endl;


    return 0;
}