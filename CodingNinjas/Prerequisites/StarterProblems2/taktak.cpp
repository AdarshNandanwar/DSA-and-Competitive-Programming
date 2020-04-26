#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("taktakin.txt", "r", stdin);
    freopen("taktakout.txt", "w", stdout);

    int a, count=0;
    cin>>a;
    while((a-1)%11 != 0)
    {
        a*=2;
        count++;
    }
    
    cout<<count<<" "<<a<<endl;

    return 0;
}