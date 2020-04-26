#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("rainin.txt", "r", stdin);
    freopen("rainout.txt", "w", stdout);

    int n, c, sum=0, a, i;
    
    cin>>n>>c;
    for(i=1; i<=n; i++)
    {
        cin>>a;
        sum+=a;
        if(sum>=c)
            break;
    }

    cout<<i;
    return 0;
}