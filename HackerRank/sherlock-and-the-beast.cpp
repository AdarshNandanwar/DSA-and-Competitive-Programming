#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    while(n--){
        ll k;
        cin>>k;
        bool flag = true;
        ll i;
        for (i = (k/3); i >= 0; i--)
        {
            if(((k-(i*3))%5) == 0){
                flag = false;
                break;
            }
        }
        ll j = (k-(i*3))/5;
        if(flag){
            cout<<-1<<endl;
        } else {
            for (ll I = 0; I < i; I++)
            {
                cout<<"555";
            }
            for (ll i = 0; i < j; i++)
            {
                cout<<"33333";
            }
            cout<<endl;
        }
    }

    return 0;
}