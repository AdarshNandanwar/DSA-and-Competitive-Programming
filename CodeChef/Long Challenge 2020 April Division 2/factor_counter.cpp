#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime(ll num){
    if(num==1) return false;
    bool flag=true;
    for(ll i = 2; i <= num / 2; i++) {
       if(num % i == 0) {
          flag = false;
          break;
       }
    }
    return flag;
}

ll factorCount(ll n){
    ll count = 0;
    for (ll i = 1; i <= n; i++)
    {
        if(!(n%i)) count++;
    }
    return count;
}

ll primeFactorCount(ll n){
    ll count = 0;
    for (ll i = 1; i <= n; i++)
    {
        if(!(n%i) && isPrime(i)) count++;
    }
    return count;
}

int main(){
    ll n = 1000;
    for (ll i = 1; i <= n; i++)
    {
        ll X, K;
        X = factorCount(i), K = primeFactorCount(i);
        if(true){
            cout<<"i: "<<i<<" ";
            cout<<"X: "<<X<<" ";
            cout<<"K: "<<K<<endl;
        }
    }
    

    return 0;
}