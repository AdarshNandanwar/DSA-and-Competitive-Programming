#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    
    ll t, n, q, flag;
    // cout<<"judge t n q: ";
    cin>>t>>n>>q;
    for(int k = 1; k<=t; k++){
        if(n == 0){
            cout<<endl;
        } else if(n == 1){
            cout<<1<<endl;
        } else if(n == 2){
            cout<<1<<" "<<2<<endl;
        } else {
            vector<ll> res = {1,2};
            unordered_map<string, ll> cache;
            for(int i = 3; i<=n; i++){
                ll window_lo = -1, window_hi = res.size();  // not inclusive
                ll lo = window_lo+1, hi = window_hi-1, mid;
                ll median;
                while(window_hi-window_lo > 2){
                    if(lo == hi){
                        if(lo > 0){
                            string key = to_string(res[lo-1])+","+to_string(res[lo])+","+to_string(i);
                            if(cache.count(key)) median = cache[key];
                            else {
                                cout<<res[lo-1]<<" "<<res[lo]<<" "<<i<<endl;
                                // cout<<"judge median: ";
                                cin>>median;
                                cache[key] = median;
                            }
                            if(median == res[lo-1]){
                                window_hi = lo-1;
                                hi = lo-2;
                                lo = window_lo+1;
                            } else if(median == res[lo]){
                                window_lo = lo;
                                lo = lo+1;
                                hi = window_hi-1;
                            } else if(median == i){
                                window_lo = lo-1;
                                window_hi = lo;
                            }
                        } else {
                            string key = to_string(res[lo])+","+to_string(res[lo+1])+","+to_string(i);
                            if(cache.count(key)) median = cache[key];
                            else {
                                cout<<res[lo]<<" "<<res[lo+1]<<" "<<i<<endl;
                                // cout<<"judge median: ";
                                cin>>median;
                                cache[key] = median;
                            }
                            if(median == res[lo]){
                                window_hi = lo;
                                hi = lo-1;
                                lo = window_lo+1;
                            } else if(median == res[lo+1]){
                                window_lo = lo+1;
                                lo = lo+2;
                                hi = window_hi-1;
                            } else if(median == i){
                                window_lo = lo;
                                window_hi = lo+1;
                            }
                        }
                    } else {
                        string key = to_string(res[lo])+","+to_string(res[hi])+","+to_string(i);
                        if(cache.count(key)) median = cache[key];
                        else {
                            cout<<res[lo]<<" "<<res[hi]<<" "<<i<<endl;
                            // cout<<"judge median: ";
                            cin>>median;
                            cache[key] = median;
                        }
                        if(median == res[lo]){
                            window_hi = lo;
                            hi = lo-1;
                            lo = window_lo+1;
                        } else if(median == res[hi]){
                            window_lo = hi;
                            lo = hi+1;
                            hi = window_hi-1;
                        } else if(median == i){
                            mid = lo+(hi-lo)/2;
                            hi = mid;
                        }
                    }
                }
                if(window_hi-window_lo == 2){
                    if(window_lo >= 0){
                        string key = to_string(res[window_lo])+","+to_string(res[window_lo+1])+","+to_string(i);
                        if(cache.count(key)) median = cache[key];
                        else {
                            cout<<res[window_lo]<<" "<<res[window_lo+1]<<" "<<i<<endl;
                            // cout<<"judge median: ";
                            cin>>median;
                            cache[key] = median;
                        }
                        if(median == res[window_lo+1]){
                            window_lo++;
                        } else {
                            window_hi--;
                        }
                    } else {
                        string key = to_string(res[window_hi-1])+","+to_string(res[window_hi])+","+to_string(i);
                        if(cache.count(key)) median = cache[key];
                        else {
                            cout<<res[window_hi-1]<<" "<<res[window_hi]<<" "<<i<<endl;
                            // cout<<"judge median: ";
                            cin>>median;
                            cache[key] = median;
                        }
                        if(median == res[window_hi-1]){
                            window_hi--;
                        } else {
                            window_lo++;
                        }
                    }
                } 

                // cout<<"window_lo window_hi "<<window_lo<<" "<<window_hi<<endl;

                // insert the number at index "window_hi"
                res.push_back(0);
                for(int j = res.size()-1; j>window_hi; j--){
                    res[j] = res[j-1];
                }
                res[window_hi] = i;

                // cout<<"res till now: ";
                // for(auto itr:res) cout<<itr<<" ";
                // cout<<endl;
            }
            for(auto itr:res) cout<<itr<<" ";
            cout<<endl;
        }
        // cout<<"judge correct: ";
        cin>>flag;
        if(flag == 0) return 0;
    }
    
    return 0;
}