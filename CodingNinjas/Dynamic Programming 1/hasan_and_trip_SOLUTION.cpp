#include<bits/stdc++.h>
using namespace std;
 
#define ll long long 
double ans[3001];
ll x[3001], y[3001];
double f[3001];
int main()
{
    int t;
    cin>>t;
 
    for(int i=0;i<t;i++)
    {
        cin>>x[i]>>y[i]>>f[i];
        ans[i]=-DBL_MAX;
    }
    ans[0]=f[0];
    for(int i=1;i<t;i++)
    {
        for(int j=0;j<i;j++)
        {
           ans[i]=max(ans[i],ans[j]-sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
        }
        ans[i]+=f[i];
    }
    printf("%0.6lf\n", ans[t-1]);
}