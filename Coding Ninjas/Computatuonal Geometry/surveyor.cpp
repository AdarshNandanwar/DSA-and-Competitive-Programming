#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin>>s;
    ll n = s.length()+1;

    double * X = new double[n]();
    double * Y = new double[n]();
    for (ll i = 1; i < n; i++){
        ll d;
        cin>>d;
        switch(s[i-1]){
            case 'N': {
                X[i] = X[i-1];
                Y[i] = Y[i-1]+d;
                break;
            }
            case 'S': {
                X[i] = X[i-1];
                Y[i] = Y[i-1]-d;
                break;
            }
            case 'E': {
                X[i] = X[i-1]+d;
                Y[i] = Y[i-1];
                break;
            }
            case 'W': {
                X[i] = X[i-1]-d;
                Y[i] = Y[i-1];
                break;
            }
        }
    }
    double area = 0;
    for (ll i = 1; i < n-1; i++)
    {
        area += ((X[i]-X[0])*(Y[i+1]-Y[0])-(X[i+1]-X[0])*(Y[i]-Y[0]));
    }  
    cout<<floor(abs(area/2));
    return 0;
}