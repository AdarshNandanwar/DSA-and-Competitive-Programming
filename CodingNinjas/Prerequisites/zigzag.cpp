#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int arr[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin>>arr[i][j];
        }
        
    }

    int flag=1, j=0;

    
    for (int i = 0; i < N; i++)
    {
        for(int k=0; k<N; k++)
        {
            cout<<arr[j][i]<<" ";
            if(flag)
                j++;
            else
                j--;    
        }
        if(flag)
            j--;
        else
            j++;   
        if(flag)
            flag=0;
        else
            flag=1;
    }
    
    
    return 0;
}