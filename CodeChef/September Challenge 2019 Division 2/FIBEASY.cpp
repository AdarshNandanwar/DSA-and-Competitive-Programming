#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll * getFirst60FibMod(){
    ll n = 60;
    ll * arr = new ll[n];
    arr[0] = 0;
    arr[1] = 1;
    for (ll i = 2; i < 60; i++)
    {
        arr[i] = (arr[i-1] + arr[i-2])%10;
    }
    return arr;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll N;
        cin>>N;
        //highest power hp such that    2^(hp) - 1 <= N    
        if(N==1){
            cout<<0<<endl;
        } else {
            ll hp = floor(log2(N));
            ll index = ((1ull<<hp)-1)%60;        //using 1l is VERY IMPORTANT, 
                                                //else overflow occurs since 1 is by default integer 
                                                //and the value of hp goes till 59

            //now find hp'th term in single digit fib
            ll * fibTerms = getFirst60FibMod();
            // cout<<hp<<" "<<index<<" ";
            cout<<fibTerms[index]<<endl;
        }
    }
    return 0;
}