#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int N, M;
    ll counter=0;
    cin>>N>>M;
    ll* a=new ll[N];
    for (int i = 0; i < N; i++)
    {
        cin>>a[i];
    }
    ll* Q=new ll[M];

    sort(a, a+N);
    ll* ptr=a+N-1;
    queue<ll> q;

    for (int i = 0; i < M; i++)
    {
        cin>>Q[i];
        ll number;
        while(counter<Q[i]){
            if(ptr>=a && (q.front()<*ptr || q.empty())){
                number=*ptr;
                ptr--;
            }else{
                number=q.front();
                q.pop();
            }
            q.push(number/2);
            counter++;
        }
        cout<<number<<endl;
    }
    

    delete[] a;
    delete[] Q;
    return 0;    
}