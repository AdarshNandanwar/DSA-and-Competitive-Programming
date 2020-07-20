#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    ll m;
    cin>>n;
    unordered_set<ll> s;
    vector<ll> A(n);
    for(auto & i:A){ 
        cin>>i;
        s.insert(i);
    }
    cin>>m;
    vector<ll> B(m);
    for(auto & i:B){
        cin>>i;
        s.insert(i);
    } 

    s.insert(INT_MAX); // all score 2 pointes everytime

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll pa, pb, score_a, score_b, maxScore = INT_MIN, max_score_a = -1;
    for(auto i:s){
        pa = upper_bound(A.begin(), A.end(), i-1) - A.begin();
        score_a = 2*pa + 3*(n-pa);
        pb = upper_bound(B.begin(), B.end(), i-1) - B.begin();
        score_b = 2*pb + 3*(m-pb);
        if(score_a-score_b > maxScore or (score_a-score_b == maxScore and max_score_a < score_a)){
            maxScore = score_a-score_b;
            max_score_a = score_a;
        }
    }

    cout<<max_score_a<<":"<<max_score_a-maxScore<<endl;
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