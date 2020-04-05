#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll a = 0, b = INT_MAX, sum = 0;
    for (int i = 0; i < 5; i++)
    {
        ll temp;
        cin>>temp;
        a = max(temp, a);
        b = min(temp, b);
        sum += temp;
    }
    cout<<sum-a<<" "<<sum-b<<endl;
    return 0;
}