#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("dictin.txt", "r", stdin);
    freopen("dictout.txt", "w", stdout);

    int d, w, dict[1001][2], a, b, pos=0, j;

    cin>>d>>w;
    
    for(int i=0; i<d; i++)
    {
        cin>>dict[i][0]>>dict[i][1];
        pos++;
    }
    for(int i=0; i<w; i++)
    {
        cin>>a;
        for(j=0; j<pos; j++)
        {
            if(dict[j][0]==a)
            {
                cout<<dict[j][1]<<endl;
                break;
            }
        }
        if(j==pos)
            cout<<"C?"<<endl;
    }

    return 0;
}