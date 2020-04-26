#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("listin.txt", "r", stdin);
    freopen("listout.txt", "w", stdout);

    int id[1001], f, a, b, max=0;

    for(int i=0; i<1001; i++)
    {
        id[i]=0;
    }

    cin>>f;

    for(int i=0; i<f; i++)
    {
        cin>>a>>b;
        id[a]++;
        id[b]++;
        if(max<id[a])
            max=id[a];
        if(max<id[b])
            max=id[b];
    }

    for(int i=0; i<1001; i++)
    {
        if(id[i]==max)
            cout<<i<<endl;
    }

    return 0;
}