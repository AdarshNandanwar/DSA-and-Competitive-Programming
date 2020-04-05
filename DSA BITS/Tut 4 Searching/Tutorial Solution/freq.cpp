#include<bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin>>n>>x;

    vector<int> vec(n, 0);

    for(int i=0; i<n; i++) {
        cin>>vec[i];
    }

    auto lo = lower_bound(vec.begin(), vec.end(), x);   //first element not less than x
    auto hi = upper_bound(vec.begin(), vec.end(), x);   //first element greater than x

    cout<<hi-lo<<"\n";

}