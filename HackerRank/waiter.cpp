#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool * is_prime(ll n){
    bool * arr = new bool[n];
    arr[0] = arr[1] = false;
    for (ll i = 2; i < n; i++)
    {
        arr[i] = true;
        for (ll j = 2; j <= i/2; j++)
        {
            if(i%j == 0){
                arr[i] = false;
                break;
            }
        }
    }
    return arr;
}

int main(){
    ll n, q;
    cin>>n>>q;
    bool * arr = is_prime(10000);
    vector<ll> primes;
    primes.push_back(0);
    for (ll i = 0; i < 10000; i++)
    {
        if(arr[i]){
            primes.push_back(i);
        }
    }
    
    vector<stack<ll>> A, B;
    stack<ll> a, b;
    for (ll i = 0; i < n; i++)
    {
        ll temp;
        cin>>temp;
        a.push(temp);
    }
    A.push_back(a);
    B.push_back(b);
    for (ll i = 1; i <= q; i++)
    {
        stack<ll> a_next, b_next;
        stack<ll> a_prev = A[i-1];
        while(!a_prev.empty()){
            if(a_prev.top()%primes[i] == 0){
                b_next.push(a_prev.top());
            } else {
                a_next.push(a_prev.top());
            }
            a_prev.pop();
        }
        A.push_back(a_next);
        B.push_back(b_next);    
    }
    for (ll i = 1; i <= q; i++)
    {
        while(!B[i].empty()){
            cout<<B[i].top()<<endl;;
            B[i].pop();
        }
    }
    while(!A[q].empty()){
        cout<<A[q].top()<<endl;
        A[q].pop();
    }

    return 0;
}