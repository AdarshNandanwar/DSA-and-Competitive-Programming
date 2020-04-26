#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("dishin.txt", "r", stdin);
    freopen("dishout.txt", "w", stdout);

    int n, m, min, max, sum=0, count=1;
    cin>>n;
    cin>>m;
    min=m;
    max=m;
    sum+=m;
    for(int i=0; i<n-1; i++)
    {
        cin>>m;
        if(m>max)
            max=m;
        if(m<min)
            min=m;
        sum+=m;
        count++;
    }
    cout<<min<<" "<<max<<" "<<sum/count<<endl;
    return 0;
}