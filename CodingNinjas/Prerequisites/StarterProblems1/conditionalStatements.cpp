#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("sitin.txt", "r", stdin);
    freopen("sitout.txt", "w", stdout);

    int r,s,t;
    cin>>r>>s>>t;

    if(r*s>=t)
        cout<<t<<" "<<0;
    else
        cout<<r*s<<" "<<t-r*s;
    
    return 0;
}