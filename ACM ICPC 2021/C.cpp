#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    ll x, k = 0, flag = 0;
    cin>>n>>x;

    if(n%2){
        if(x == 0){
            cout<<-1;
            return;
        }
        flag = 1;
        n--;
        x--;
    }

    if(n <= x){
        cout<<1<<endl;
        return;
    }


    for(int i = 31; i>=0; i--){
        if(x&(1<<i)) flag = 1;
        if(flag){
            if((n&(1<<i)) and (x&(1<<i)) == 0){
                if(i%2) k += 1;
                else k += 2;
            } else if((n&(1<<i)) == 0 and (x&(1<<i))){
                break;
            }
        } else if(n&(1<<i)){
            if(i%2) k += 1;
            else k += 2;
        }
        // cout<<k<<" ";
    }
    // cout<<endl;
    cout<<k+flag<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


/*

11011

1111110
0011110

0100000
0100000
0100000

1100000


3+1+2 = 6

0000000
1010100


*/



// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         long long int n;
//         cin>>n;
//         long long int x;
//         cin>>x;
//         if(n<=x)
//         {
//             cout<<1<<"\n";
//             continue;
//         }
//         long long int ans=0;
//         if(x==0 && n%2!=0)
//         {
//             cout<<"-1\n";
//             continue;
//         }
//         int flag=-1;
//         int count=0;
//         int a[31]={0};
//         int b[31]={0};
//         if(n%2!=0)
//         {
//             count+=1;
//             flag=0;
//             n=n-1;
//             x=x-1;
//         }
//         for(int i=0;i<31;i++)
//         {
//             a[i]=n%2;
//             b[i]=x%2;
//             n=n/2;
//             x=x/2;
//         }
//         for(int i = 30;i>=0;i--)
//         {
//             if(a[i]==1 && b[i]==0)
//             {
//                 if(i%2==0)
//                 {
//                     count+=2;
//                 }
//                 else
//                 {
//                     count+=1;
//                 }
//             }
//             else if(a[i]==0 && b[i]==1)
//             {
//                 if(flag==-1)
//                 {
//                     count+=1;
//                 }
//                 flag=1;
//                 break;
//             }
//             else if(a[i]==1 && b[i]==1 && flag==-1)
//             {
//                 count+=1;
//                 flag=0;
//             }
//             else if(a[i]==1 && b[i]==1 && flag==0)
//             {

//             }
//         }
//         cout<<count<<"\n";
//     }
//     return 0;
// }
// 3210
// 0011
// 0010