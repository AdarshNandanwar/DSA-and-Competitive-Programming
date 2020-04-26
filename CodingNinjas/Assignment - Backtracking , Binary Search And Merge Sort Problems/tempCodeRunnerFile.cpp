#include<bits/stdc++.h>
using namespace std;

bool check(int k, int balls){
    if(k==0){
        return false;
    }
    int count=0, n=balls;
    while(n>0){
        if(n>=k){
            count+=k;
            n-=k;
        }else{
            count+=n;
            n=0;
            break;
        }
        if(n>0){
            n-=(n/10);
        }
    }
    if(count >= balls/2){
        return true;
    }else{
        return false;
    }
}

int main()
{
    int n;
    cin>>n;
    int start = 0, end = n, mid;

    while(start <= end){
        mid = start + (end-start)/2;
        if(check(mid, n)){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    cout<<start<<endl;

	return 0;
}