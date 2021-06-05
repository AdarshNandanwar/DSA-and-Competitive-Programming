#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef unsigned long long ll;


void swap(ll & a, ll & b){
    ll temp = a;
    a = b;
    b = temp;
}

ll helper(ll b1, ll b2, ll b3, ll a, ll b, ll c){
    // cout<<b1<<" "<<b2<<" "<<b3<<endl;
    ll sec = a%((ll)720*(ll)60);
    ll min = b%((ll)12*(ll)60);
    ll hrs = c%((ll)1*(ll)60);
    // cout<<sec/720<<" "<<min/12<<" "<<hrs<<endl;
    if(b1 == sec/720 and b2 == min/12 and b3 == hrs/1){
        cout<<b1<<" "<<b2<<" "<<b3<<endl;
        return 1;
    }
    return 0;
}

void solve(ll t_id){

    ll n, ans;
    ll a, b, c;
    cin>>a>>b>>c;



    cout<<"angles: ";
    ll a1 = (a/((ll)10000000000))/12;
    ll a2 = (b/((ll)10000000000))/12;
    ll a3 = (c/((ll)10000000000))/12;
    cout<<a1<<" "<<a2<<" "<<a3<<endl;
    cout<<"division: ";
    a1 /= 6;
    a2 /= 6;
    a3 /= 6;
    cout<<a1<<" "<<a2<<" "<<a3<<endl;


    ll min_angle = 60;
    if(a1<a2){
        if(a1<a3){
            min_angle = a1;
        } else {
            min_angle = a3;
            swap(a1, a3);
        }
    } else {
        if(a2<a3){
            min_angle = a2;
            swap(a1, a2);
        } else {
            min_angle = a3;
            swap(a1, a3);
        }
    }

    a1 -= min_angle;
    a2 -= min_angle;
    a3 -= min_angle;
    ll sec, min, hrs;

    for(ll offset = 0; offset<60; offset++){
        ll b1 = (a1+offset)%60;
        ll b2 = (a2+offset)%60;
        ll b3 = (a3+offset)%60;

        // cout<<b1<<" "<<b2<<" "<<b3<<endl;

        if(helper(b1, b2, b3, a, b, c)) break;
        if(helper(b1, b3, b2, a, c, b)) break;
        if(helper(b2, b1, b3, b, a, c)) break;
        if(helper(b2, b3, b1, b, c, a)) break;
        if(helper(b3, b1, b2, c, a, b)) break;
        if(helper(b3, b2, b1, c, b, a)) break;

    }


    // cout<<"values: <from tick, from lower div>"<<endl;
    // ll ht = (a/((ll)1*60*60*1000000000));
    // ll mt = (b/((ll)12*60*1000000000));
    // ll st = (c/((ll)720*1000000000));
    // ll hl = (b/((ll)12*60*1000000000))/60;
    // ll ml = (c/((ll)720*1000000000))/60;

    // ll hd = (a/((ll)10000000000))/12;
    // ll md = (b/((ll)10000000000))/12;
    // ll sd = (c/((ll)10000000000))/12;

    // ll hl = (b/((ll)12*60*1000000000))/60;
    // ll ml = (c/((ll)720*1000000000))/60;
    // cout<<ht<<" "<<hl<<endl;
    // cout<<mt<<" "<<ml<<endl;
    // cout<<st<<" "<<endl;

    // for(ll i = 0; i<360*360; i++){  // in min
    //     // ht = ((a+i*(ll)720)/((ll)1*60*60*1000000000));
    //     // mt = ((b+i*(ll)720)/((ll)12*60*1000000000));
    //     // st = ((c+i*(ll)720)/((ll)720*1000000000));
    //     // ml = st/60;
    //     // ll hl1 = st/3600;
    //     // ll hl2 = mt/60;

    //     // if(mt == ml and ht == hl1 and ht == hl2){
    //     //     cout<<"found"<<endl;
    //     //     cout<<i<<endl;
    //     //     break;
    //     // }
    //     hd = (a/((ll)10000000000))/12;
    //     md = (b/((ll)10000000000))/12;
    //     sd = (c/((ll)10000000000))/12;
    //     ml = st/60;
    //     ll hl1 = st/3600;
    //     ll hl2 = mt/60;

    //     if(hd == md and ht == hl1 and ht == hl2){
    //         cout<<"found"<<endl;
    //         cout<<i<<endl;
    //         break;
    //     }
    // }


    


    


    cout<<"Case #"<<t_id+1<<": "<<ans<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    for(ll i = 0; i<t; i++){
        solve(i);
    }

    return 0;
}