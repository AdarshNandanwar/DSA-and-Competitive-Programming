#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b)  
{  
    return (a*b)/__gcd(a, b);  
} 

int n;

void solve(){

    scanf("%d", &n);
    vector<int> lcm_v;
    vector<set<int>> pages_v;
    for (int i = 1; i <= n; i++)
    {
        bool placed = false;
        for(int j = 0; j < lcm_v.size(); j++){
            if(__gcd(lcm_v[j], i) == 1){
                pages_v[j].insert(i);
                lcm_v[j] = lcm(lcm_v[j], i);
                placed = true;
                break;
            }
        }
        if(!placed){
            lcm_v.push_back(i);
            set<int> s;
            s.insert(i);
            pages_v.push_back(s);
        }
    }

    int lcm_v_size = lcm_v.size(), i_size;
    printf("%d\n", lcm_v_size);
    for(auto i:pages_v){
        i_size = i.size();
        printf("%d ", i_size);
        for(auto j:i){
            printf("%d ", j);
        }
        printf("\n");
    }

}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}