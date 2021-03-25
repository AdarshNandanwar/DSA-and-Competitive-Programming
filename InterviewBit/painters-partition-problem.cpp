// https://www.interviewbit.com/problems/painters-partition-problem/

bool isValid(int availableWorkers, int B, vector<int> & C, long time){
    long curTime = 0, n = C.size();
    for(int i = 0; i<n; i++){
        if(curTime + ((long)B*C[i]) <= time){
            curTime += ((long)B*C[i]);
        } else {
            availableWorkers--;
            if(availableWorkers == 0) return 0;
            curTime = ((long)B*C[i]);
            if(curTime > time) return 0;
        }
    }
    return 1;
}

int Solution::paint(int A, int B, vector<int> &C) {
    long sum = 0;
    for(auto i:C) sum += i;
    
    //  fffttt first true
    long lo = *max_element(C.begin(), C.end()), hi = sum*B, mid;
    
    while(lo<hi){
        mid = lo+(hi-lo)/2;
        if(isValid(A, B, C, mid)){
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    if(isValid(A, B, C, lo)){
        return lo%10000003;
    } else {
        return -1;
    }
}

// Alternate Code

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 10000003

bool isValid(ll A, ll B, vector<ll> & v, ll t){
    ll n = v.size(), cur_time_left = t;
    for(ll i = 0; i<n; i++){
        if(v[i]*B>cur_time_left){
            A--;
            cur_time_left = t;
        }
        if(A == 0) return false;
        cur_time_left -= v[i]*B;
    }
    return true;
}

int main(){
    ll A, B, n;
    cin>>A>>B>>n;
    vector<ll> C(n, 0);
    for(ll i = 0; i<n; i++){
        cin>>C[i];
    }
    ll max_C = *max_element(C.begin(), C.end());
    ll sum_C = accumulate(C.begin(), C.end(), 0);

    ll lo = max_C*B, hi = sum_C*B, mid;
    
    // FFTT
    // first T
    
    while(lo<hi){
        mid = lo+(hi-lo)/2;
        if(isValid(A, B, C, mid)){
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    if(isValid(A, B, C, lo)){
        cout<<lo%MOD<<endl;
    } else {
        cout<<-1<<endl;
    }

    return 0;
}