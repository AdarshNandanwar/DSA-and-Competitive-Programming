#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    double * X = new double[n];
    double * Y = new double[n];
    for (ll i = 0; i < n; i++)
        cin>>X[i];
    for (ll i = 0; i < n; i++)
        cin>>Y[i];
    double area = 0;
    for (ll i = 1; i < n-1; i++)
    {
        area += ((X[i]-X[0])*(Y[i+1]-Y[0])-(X[i+1]-X[0])*(Y[i]-Y[0]));
    }  
    cout<<floor(abs(area/2))<<endl;
    
    return 0;
}