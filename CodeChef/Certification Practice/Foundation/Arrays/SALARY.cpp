#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int minimum=INT_MAX, sum = 0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin>>temp;
            sum+=temp;
            minimum = min(minimum, temp);
        }
        sum-=(n*minimum);
        cout<<sum<<endl;
    }
}