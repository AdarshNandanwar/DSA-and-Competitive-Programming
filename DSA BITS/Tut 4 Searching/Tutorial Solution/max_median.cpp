#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;

bool can_do(int median) {
    int ops=0;

    for(int i=n/2; i<n; i++) {
        if(median-a[i] > 0) {
            ops += median-a[i];
            if(ops>k)
                return false;
        }
        else
            break;
    }

    return (ops<=k);
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;

    int temp;
    for(int i=0; i<n; i++) {
        cin>>temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());

    int lo = 1;
    int hi = 2e9;   //2,000,000,000
                    //int range 4 bytes
    int mid;

    //int iter=0;
    while(lo<hi) {
        // iter++;
        // if(iter>40)
        //     break;
        
        mid = lo + (hi-lo+1)/2;
        //cout<<lo<<" "<<mid<<" "<<hi<<" "<<can_do(mid)<<"\n";

        if(can_do(mid)) {
            lo = mid;
        }
        else {
            hi = mid-1;
        }
    }

    cout<<lo<<"\n";

}