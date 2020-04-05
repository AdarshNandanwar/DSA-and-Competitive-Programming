#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll h, w;
    cin>>h>>w;
    ll ** arr = new ll*[h];
    for (ll i = 0; i < h; i++)
    {
        arr[i] = new ll[w];
        for (ll j = 0; j < w; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    
    ll area = 2*h*w;

    for (ll i = 0; i < h; i++)
    {
        area += arr[i][0];
        area += arr[i][w-1];
    }
    for (ll i = 0; i < w; i++)
    {
        area += arr[0][i];
        area += arr[h-1][i];
    }
    
    // delta in adj towers

    for (ll i = 1; i < h; i++)
    {
        for (ll j = 0; j < w; j++)
        {
            area += abs(arr[i-1][j] - arr[i][j]);
        }
    }
    for (ll i = 0; i < h; i++)
    {
        for (ll j = 1; j < w; j++)
        {
            area += abs(arr[i][j-1] - arr[i][j]);
        }
    }

    cout<<area<<endl;

    for (ll i = 0; i < h; i++)
    {
        delete [] arr[i];
    }
    delete [] arr;
    return 0;
}