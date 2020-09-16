#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cout<<stoi("11111111111155555555")<<endl;


    n =5;
    map<int, list<int>::iterator> m;
    list<int> ll;
    for(int i=1; i<=n; i++){
        ll.push_front(i);
        m[i] = ll.begin();
    }

    for(auto i:ll){
        cout<<i<<" ";
    } cout<<endl;

    for(auto i:m){
        cout<<i.first<<" "<<*(i.second)<<endl;
    }

    cout<<endl;

    auto it = ll.begin();
    it = next(it);
    ll.insert(it, 6);
    m[6] = prev(it);

    for(auto i:ll){
        cout<<i<<" ";
    } cout<<endl;

    for(auto i:m){
        cout<<i.first<<" "<<*(i.second)<<endl;
    }

    cout<<endl;

}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // string A = ".aaaa.a..1.";
    // istringstream issa(A);
    // string s;
    // while(getline(issa, s, '.')){
    //     cout<<s<<endl;
    // }
    // cout<<"end: "<<s<<endl;
    // cout<<1e3<<endl;
    int a = INT_MIN;
    // cout<<a<<" "<<a-1<<" "<<-a<<endl;
    cout<<0b1111<<endl;
    return 0;
}