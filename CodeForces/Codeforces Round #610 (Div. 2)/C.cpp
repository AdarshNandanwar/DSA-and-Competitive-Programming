#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll calculate_extra_points(ll time_left, ll easy_left, ll hard_left, ll a, ll b){
    ll extra_points = 0;
    if(time_left/a >= easy_left){
        time_left -= (a*easy_left);
        extra_points += easy_left;
        if(time_left/b >= hard_left){
            extra_points += hard_left;
        } else {
            extra_points += (time_left/b);
        }
    } else {
        extra_points += (time_left/a);
    }
    return extra_points;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, T, a, b, easy_count = 0, hard_count = 0;
        cin>>n>>T>>a>>b;
        bool * difficulty = new bool[n];
        ll * manditory_time = new ll[n];
        for (ll i = 0; i < n; i++)
        {
            cin>>difficulty[i];
            if(difficulty[i]){
                hard_count++;
            } else {
                easy_count++;
            }
        }
        for (ll i = 0; i < n; i++)
        {
            cin>>manditory_time[i];
        }
        
        ll current_easy_count = 0, current_hard_count = 0;
        ll * min_time_required = new ll[T+1]();
        ll * min_easy_required = new ll[T+1]();
        ll * min_hard_required = new ll[T+1]();
        for (ll i = 0; i < n; i++)
        {
            if(difficulty[i]){
                min_time_required[manditory_time[i]] += b;
                min_hard_required[manditory_time[i]]++;
            } else {
                min_time_required[manditory_time[i]] += a;
                min_easy_required[manditory_time[i]]++;
            }
        }
        
        for (ll i = 1; i < T+1; i++)
        {
            min_time_required[i] += min_time_required[i-1];
            min_easy_required[i] += min_easy_required[i-1];
            min_hard_required[i] += min_hard_required[i-1];
        }

        ll * time_left = new ll[T+1];
        for (ll i = 0; i < T+1; i++)
        {
            time_left[i] = i - min_time_required[i];
        }
        ll * points = new ll[T+1]();
        for (ll i = 0; i < T+1; i++)
        {
            if(time_left[i] <0 ){
                points[i] = 0;
            } else {
                points[i] = min_easy_required[i] + min_hard_required[i];
                points[i] += calculate_extra_points(time_left[i], easy_count - min_easy_required[i], hard_count - min_hard_required[i], a, b);
            }
        }

        cout<<*max_element(points, points+T+1)<<endl;
                
        delete [] difficulty;
        delete [] manditory_time;
        delete [] min_time_required;
        delete [] min_easy_required;
        delete [] min_hard_required;
        delete [] time_left;
        delete [] points;

    }
    return 0;
}