#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, ans;
    cin>>n;
    if(n == 1){
        cout<<1<<endl;
    } else {
        ll * arr = new ll[n];
        ll * trend = new ll[n]();
        ll * final_arr = new ll[n];

        for (ll i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        
        for (ll i = 1; i < n; i++)
        {
            if(arr[i-1] < arr[i]){
                trend[i] = trend[i-1]+1;
            } else if(arr[i-1] > arr[i]){
                trend[i] = trend[i-1]-1;
            } else {
                trend[i] = trend[i-1];
            }
        }

        ll min_ele = *min_element(trend, trend+n);
        ll increment = 1-min_ele;
        for (ll i = 0; i < n; i++)
        {
            trend[i] += increment;
        }
        
        
        
        vector<ll> points;
        for (ll i = 1; i < n-1; i++)
        {
            if(trend[i-1] < trend[i] && trend[i] > trend[i+1]){
                points.push_back(i);
            } else if(trend[i-1] == trend[i] || trend[i] == trend[i+1]){
                points.push_back(i);
            }
        }


        if(points.size() == 0){
            for (ll i = 0; i < n; i++)
            {
                final_arr[i] = trend[i];
            }
            
        } else {
            if(points[0] > 0){
                ll min_sub_ele = *min_element(trend, trend+points[0]);
                ll sub_increment = 1-min_sub_ele;
                for (ll j = 0; j < points[0]; j++)
                {
                    trend[j] += sub_increment;
                }
            }

            for (ll i = 0; i < points.size()-1; i++)
            {
                if(points[i+1] - points[i] > 1){
                    ll min_sub_ele = *min_element(trend+points[i]+1, trend+points[i+1]);
                    ll sub_increment = 1-min_sub_ele;
                    for (ll j = points[i]+1; j < points[i+1]; j++)
                    {
                        trend[j] += sub_increment;
                    }
                }
            }

            
            
            ll last_index = points.size()-1;
            if(points[last_index] < n-1){
                ll min_sub_ele = *min_element(trend+points[last_index]+1, trend+n);
                ll sub_increment = 1-min_sub_ele;
                for (ll j = points[last_index]+1; j < n; j++)
                {
                    trend[j] += sub_increment;
                }
            }


            for (ll i = 0; i < n; i++)
            {
                final_arr[i] = trend[i];
            }

            for (ll i = 0; i < points.size(); i++)
            {
                if(trend[points[i]+1] == trend[points[i]] && trend[points[i]-1] == trend[points[i]]){
                    final_arr[points[i]] = 1;
                } else if(trend[points[i]+1] == trend[points[i]]){
                    final_arr[points[i]] = trend[points[i]-1] + 1;
                } else if(trend[points[i]-1] == trend[points[i]]){
                    final_arr[points[i]] = trend[points[i]+1] + 1;
                } else {
                    final_arr[points[i]] = max(trend[points[i]-1], trend[points[i]+1]) + 1;
                }
            }
        }



        ll sum = 0;

        for (ll i = 0; i < n; i++)
        {
            sum += final_arr[i];
        }
        
        cout<<sum<<endl;
        
        

        delete [] arr;
        delete [] trend;
        delete [] final_arr;
    }
    
    return 0;
}