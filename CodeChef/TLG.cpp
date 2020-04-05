#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, max_lead=-1, winner=-1, sin, tin;
    cin>>n;
    int* s = new int[n];
    int* t = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin>>sin>>tin;
        if(!i){
            *(s+i)=sin;
            *(t+i)=tin;
        }
        else{
        *(s+i)=*(s+i-1)+sin;
        *(t+i)=*(t+i-1)+tin;
        }

        if(abs(*(s+i)-*(t+i)) > max_lead)
        {
            max_lead = abs(*(s+i)-*(t+i));
            if(*(s+i) > *(t+i))
            {
                winner = 1;
            }
            else
            {
                winner = 2;
            }
        }
    }
    
    cout<<winner<<" "<<max_lead;

    delete[] s;
    delete[] t;
    
    return 0;
}