#include<bits/stdc++.h>
using namespace std;

// int countPrime(int n){
//     int count = 0;
//     for (int i = 2; i <= n; i++)
//     {
//         int factors = 0;
//         for (int j = 1; j <= sqrt(i); j++)
//         {
//             if(i%j==0){
//                 if(j*j == i){
//                     factors++;
//                 } else {
//                     factors+=2;
//                 }
//             }
//         }
//         if(factors==2){
//             count++;
//         }
//     }
//     return count;
// }

//SIEVE OF ERATOSTHENES

int countPrime(int n){
    bool * arr = new bool[n+1];
    for (int i = 0; i < n+1; i++)
    {
        arr[i] = true;
    }
    arr[0] = false;
    arr[1] = false;
    for (int i = 2; i*i <= n; i++)
    {
        if(arr[i]){
            for (int j = i*i; j <= n;)
            {
                arr[j] = false;
                j+=i;
            }
        }
    }
    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        if(arr[i]){
            count++;
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    
    cout<<countPrime(n)<<endl;
    
    return 0;
}