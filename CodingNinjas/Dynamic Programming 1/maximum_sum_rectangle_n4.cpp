#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c;
    cin>>r>>c;
    int ** input = new int*[r];
    int ** sum_arr = new int*[r+1];
    for (int i = 0; i < r; i++)
    {
        input[i] = new int[c];
    }
    for (int i = 0; i < r+1; i++)
    {
        sum_arr[i] = new int[c+1];
    }
    
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>input[i][j];
        }
    }


    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sum_arr[i][j] = 0;
            for (int k = i; k < r; k++)
            {
                for (int l = j; l < c; l++)
                {
                    sum_arr[i][j] += input[k][l];
                }
                
            }
            
        }
        
    }
    for (int i = 0; i < r+1; i++)
    {
        sum_arr[i][c] = 0;
    }
    for (int i = 0; i < c+1; i++)
    {
        sum_arr[r][i] = 0;
    }
    
    int max_area = INT_MIN, area;
    for (int si = 0; si < r; si++)
    {
        for (int sj = 0; sj < c; sj++)
        {
            for (int ei = si+1; ei < r+1; ei++)
            {
                for (int ej = sj+1; ej < c+1; ej++)
                {
                    max_area = max(max_area, sum_arr[si][sj] + sum_arr[ei][ej] - sum_arr[si][ej] - sum_arr[ei][sj]);
                }
                
            }
            
        }
        
    }
    
    cout<<max_area<<endl;

    for (int i = 0; i < r; i++)
    {
        delete [] input[i];
        delete [] sum_arr[i];
    }
    delete [] input;
    delete [] sum_arr;
    return 0;
}
