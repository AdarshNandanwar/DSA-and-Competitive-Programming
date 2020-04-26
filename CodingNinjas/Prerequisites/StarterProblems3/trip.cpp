#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("tripin.txt", "r", stdin);
    freopen("tripout.txt", "w", stdout);

    int n, a[50001], temp, count=0;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>temp;
        if(temp%3==0)
        {
            a[i]=1;
            count++;
        }
        else
        {
                a[i]=0;
        }
    }
    if(count)
    {
        cout<<count<<endl;
        for(int i=0; i<n; i++)
        {
            if(a[i])
                cout<<i+1<<" ";
        } 
    }
    else
    {
        cout<<"Nothing here!";
    }
    
    return 0;
}