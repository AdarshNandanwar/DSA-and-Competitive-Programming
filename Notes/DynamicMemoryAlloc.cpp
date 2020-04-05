#include<bits/stdc++.h>
using namespace std;

int main()
{
    int r,c;
    cin>>r>>c;

    double** ptrptr = NULL;
    ptrptr = new double*[r];

    for (int i = 0; i < r; i++)
    {
        ptrptr[i] = new double[c];
    }
    

    for (int i = 0; i < r; i++)
    {
        for (int  j = 0; j < c; j++)
        {
            cin>> *(*(ptrptr + i) + j);
        }
        
    }

    for (int i = 0; i < r; i++)
    {
        for (int  j = 0; j < c; j++)
        {
            cout<< *(*(ptrptr + i) + j) << " ";
        }
        cout<<endl;
    }
    
    return 0;
}