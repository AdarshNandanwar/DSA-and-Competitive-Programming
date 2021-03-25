// http://codeforces.com/problemset/problem/166/C

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

// Method 1 (Redundant code):

// void solve(){
//     ll x;
//     cin>>n>>x;
//     vector<int> v(n);
//     for(auto & i:v) cin>>i;
//     sort(v.begin(), v.end());
//     auto lb = lower_bound(v.begin(), v.end(), x), ub = upper_bound(v.begin(), v.end(), x);
//     int less = lb-v.begin(), more = v.end()-ub, equal = ub-lb;
//     int m = (n-1)/2, bestM, rightCount, leftCount, res;

//     if(binary_search(v.begin(), v.end(), x)){
//         if(less <= m and m <less+equal){
//             res = 0;
//         } else {
//             if(less+equal <= m){
//                 // insert elements in the left
//                 bestM = less+equal-1;
//                 rightCount = n-bestM-1;
//                 leftCount = bestM;

//                 res = rightCount-leftCount-1;
//             } else {
//                 // insert elements in the right
//                 bestM = less;
//                 rightCount = n-bestM-1;
//                 leftCount = bestM;
//                 res = leftCount-rightCount;
//             }
//         }
//     } else {
//         if(more-less == 0 or more-less == 1){
//             res = 1;
//         } else {
//             if(more > less){
//                 res = more-less;
//             } else {
//                 res = less-more+1;
//             }
//         }
//     }
//     cout<<res<<endl;
// }


// Method 1 (Removed Redundant Code):

void solve(){
    ll x;
    cin>>n>>x;
    vector<int> v(n);
    for(auto & i:v) cin>>i;
    sort(v.begin(), v.end());
    auto lb = lower_bound(v.begin(), v.end(), x), ub = upper_bound(v.begin(), v.end(), x);
    int less = lb-v.begin(), more = v.end()-ub, equal = ub-lb;
    int m = (n-1)/2, bestM, rightCount, leftCount, res;

    if(less <= m and m <less+equal){
        res = 0;
    } else {
        if(less+equal <= m){
            // insert elements in the left
            bestM = less+equal-1;
            rightCount = n-bestM-1;
            leftCount = bestM;

            res = rightCount-leftCount-1;
        } else {
            // insert elements in the right
            bestM = less;
            rightCount = n-bestM-1;
            leftCount = bestM;
            res = leftCount-rightCount;
        }
    }

    cout<<res<<endl;
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    while(t--){
        solve();
    }
    return 0;
}