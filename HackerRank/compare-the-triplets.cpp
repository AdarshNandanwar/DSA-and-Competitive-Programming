#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll * a = new ll[3];
    ll * b = new ll[3];
    ll pt_a=0, pt_b=0;
    for (int i = 0; i < 3; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cin>>b[i];
    }
    
    for (int i = 0; i < 3; i++)
    {
        if(a[i]>b[i]){
            pt_a++;
        } else if (a[i] < b[i]){
            pt_b++;
        }
    }
    cout<<pt_a<<" "<<pt_b<<endl;
    return 0;
}