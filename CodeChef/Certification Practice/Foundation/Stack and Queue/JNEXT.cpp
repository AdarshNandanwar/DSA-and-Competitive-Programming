






// logic fails for 698731





#include<bits/stdc++.h>
using namespace std;
#include<queue>
typedef long long ll;

void swap(ll & a, ll & b){
    a = a+b;
    b = a-b;
    a = a-b;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        queue<ll> q;
        cin>>n;
        ll * arr = new ll[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        bool isLoopComplete = false;
        int i;
        ll temp;
        for (i = n-1; i > 0; i--)
        {
            if(arr[i-1]>=arr[i]){
                q.push(arr[i]);
                if(i==1){
                    isLoopComplete = true;
                }
            }
            else {
                swap(arr[i], arr[i-1]);
                temp = arr[i];
                break;
            }
        }
        bool isTempDisplayed = false;
        if(isLoopComplete){
            cout<<-1<<endl;
        } else { 
            for (int j = 0; j < i; j++)
            {
                cout<<arr[j];
            }
            while(!q.empty()){
                if(isTempDisplayed || temp>=q.front()){
                    cout<<q.front();
                    q.pop();
                } else {
                    cout<<temp;
                    isTempDisplayed = true;
                }
            }
            if(!isTempDisplayed){
                cout<<temp;
            }
            cout<<endl;
        }
        delete [] arr;
    }
    return 0;
}