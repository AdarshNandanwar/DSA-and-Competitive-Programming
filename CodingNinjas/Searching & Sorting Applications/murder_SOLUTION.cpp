#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m=INT_MAX;
    cin>>n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        int input;
        cin>>input;
        arr[i]=input-i;
        if(arr[i]<=0){
            cout<<i+1<<endl;
            return 0;
        }
        m=min(m, arr[i]);
    }
    
    int x=((m/n)+1)*n;
    for (int i = 0; i < n; i++)
    {
        arr[i]-=x;
        if(arr[i]<=0){
            cout<<i+1<<endl;
            return 0;
        }
    }
    
    delete[] arr;
    return 0;
}