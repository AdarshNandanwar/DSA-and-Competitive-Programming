#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, sum = 0, mysum = 0;
    cin>>n;
    int * coins = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>coins[i];
        sum+=coins[i];
    }
    sort(coins, coins+n, greater<int>());
    int i;
    for (i = 0; i < n; i++)
    {
        if(mysum<=sum){
            mysum+=coins[i];
            sum-=coins[i];
        } else {
            break;
        }
    }
    cout<<i<<endl;
    return 0;
}