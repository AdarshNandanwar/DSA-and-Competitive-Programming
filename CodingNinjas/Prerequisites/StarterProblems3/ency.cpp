#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("encyin.txt", "r", stdin);
    freopen("encyout.txt", "w", stdout);

    int n, q, p[10001], x;

    cin>>n>>q;
    for(int i=0; i<n; i++)
    {
        cin>>p[i];
    }

    for(int i=0; i<q; i++)
    {
        cin>>x;
        cout<<p[x-1]<<endl;
    }
    return 0;
}