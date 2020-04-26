#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, max_sum=INT_MIN, sum=0;
    cin>>n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
        max_sum=max(max_sum, sum);
        if(sum<0){
            sum=0;
        }
    }
    cout<<max_sum;
    
    return 0;
}