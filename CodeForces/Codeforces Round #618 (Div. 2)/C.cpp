#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll n;
    cin>>n;

    ll * arr = new ll[n]();
    ll * mask = new ll[40]();
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (ll i = 0; i < 32; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if(arr[j] & ((ll)1<<i)){
                mask[i]++;
            }
        }
    }
    for (ll i = 0; i < 32; i++)
    {
        if(mask[i]>1){
            mask[i] = 0;
        }
        // cout<<mask[i]<<" ";
    }
    // cout<<endl;
    list<ll> li;
    // for (ll i = 0; i < n; i++)
    // {
    //     li.push_back(i);
    // }
    ll last = 0;
    bool first_mask = false;
    for (ll i = 31; i >= 0; i--)
    {
        if(mask[i]){
            cout<<"mask at: "<<i<<endl;
            if(!first_mask){
                cout<<"first mask at: "<<i<<endl;
                for (ll j = 0; j < n; j++)
                {
                    if(arr[j] & ((ll)1<<i)){
                        li.push_back(j);
                        cout<<"add"<<arr[j]<<"at mask: "<<i<<endl;
                    }
                }
                first_mask = true;
            } else {

                list<ll>::iterator itr;
                for (itr = li.begin(); itr != li.end(); itr++){
                    if((*itr) & ((ll)1<<i)){
                        continue;
                    } else {
                        last = (*itr);
                        // li.erase(itr);
                        // itr--;
                        cout<<"remove"<<arr[last]<<"at mask: "<<i<<endl;
                    }
                }
                
                // for (ll j = 0; j < n; j++)
                // {
                //     if(arr[j] & ((ll)1<<i)){
                //         continue;
                //     } else {
                //         li.remove(j);
                //         last = j;
                //         // cout<<"remove"<<arr[last]<<"at mask: "<<i<<endl;
                //     }
                // }
            }
        }
    }
    cout<<"size"<<li.size()<<endl;
    if(li.size()){
        cout<<arr[li.front()]<<" ";
        for (ll i = 0; i < n; i++)
        {
            if(i != li.front()){
                cout<<arr[i]<<" ";
            }
        }
        cout<<endl;
    } else {
        bool skipped = false;
        cout<<arr[last]<<" ";
        for (ll i = 0; i < n; i++)
        {
            if(i != last){
                cout<<arr[i]<<" ";
            } else {
                if(skipped){
                    cout<<arr[i]<<" ";
                } else {
                    skipped = true;
                }
            }
        }
        cout<<endl;
    }
    

    delete [] arr;
    return 0;
}