#include<bits/stdc++.h>
#include<map>
typedef long long ll;
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        map<int, int> m;
        int n;
        cin>>n;
        while(n--){
            int a, b;
            cin>>a>>b;
            m[a] = max(m[a], b);
        }
        ll sum = 0;
        for (int i = 1; i <= 8; i++)
        {
            sum+=m[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}