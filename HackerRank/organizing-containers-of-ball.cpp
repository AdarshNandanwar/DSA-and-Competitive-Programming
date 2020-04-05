#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll q;
    cin>>q;
    while(q--){
        ll n;
        cin>>n;
        ll ** arr = new ll*[n];
        ll * col_sum = new ll[n]();
        ll * row_sum = new ll[n]();
        

        for (ll i = 0; i < n; i++)
        {
            arr[i] = new ll[n];
            for (ll j = 0; j < n; j++)
            {
                cin>>arr[i][j];
            }
            
        }
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                row_sum[i] += arr[i][j];
                col_sum[j] += arr[i][j];
            }    
        }
        
        
        sort(col_sum, col_sum+n);
        sort(row_sum, row_sum+n);

        bool possible = true;

        for (ll i = 0; i < n; i++)
        {
            if(col_sum[i] != row_sum [i]){
                possible = false;
                break;
            }
        }
        
        if(possible){
            cout<<"Possible\n";
        } else {
            cout<<"Impossible\n";
        }

        delete [] col_sum;
        delete [] row_sum;
        

        for (ll i = 0; i < n; i++)
        {
            delete [] arr[i];
        }
        delete [] arr;
    }

    return 0;
}