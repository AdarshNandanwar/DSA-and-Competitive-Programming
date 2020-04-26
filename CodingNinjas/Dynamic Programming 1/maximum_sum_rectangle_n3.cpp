#include<bits/stdc++.h>
using namespace std;

int kadane(int * arr, int size){
    int max_sum=INT_MIN;
    int sum=0;
    for (int i = 0; i < size; i++)
    {
        sum+=arr[i];
        max_sum = max(max_sum, sum);
        if(sum<0){
            sum=0;
        }
    }
    return max_sum;
}

int main(){
    int r,c;
    cin>>r>>c;
    int ** input = new int*[r];
    int * arr = new int[r];
    for (int i = 0; i < r; i++)
    {
        input[i] = new int[c];
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>input[i][j];
        }
        
    }
    
    
    int max_sum = INT_MIN;

    for (int start = 0; start < c; start++)
    {
        for (int i = 0; i < r; i++)
        {
            arr[i] = 0;
        }
        
        for (int end = start; end < c; end++)
        {
            for (int i = 0; i < r; i++)
            {
                arr[i]+=input[i][end];
                
            }
            //kadane's algorithm            
            max_sum = max(max_sum, kadane(arr, r));
        }
        
    }
    
    cout<<max_sum<<endl;
    for (int i = 0; i < r; i++)
    {
        delete [] input[i];
    }
    delete [] input;
    delete [] arr;
    return 0;
}