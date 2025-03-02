#include<vector>
#include<iostream>

using namespace std;

vector<int> sieve_of_eratosthemes(int n){
    vector<bool> isPrime(n+1, true);

    isPrime[1] = false;
    for(int i=2; i*i<=n; i++){
        if(isPrime[i] == false){
            continue;
        }
        for(int j=i*i; j<=n; j+=i){
            isPrime[j] = false;
        }
    }

    vector<int> primes;
    for(int i=2; i<=n; i++){
        if(isPrime[i] == true){
            primes.push_back(i);
        }
    }

    return primes;
}

int main(){
    for(auto prime:sieve_of_eratosthemes(1000)){
        cout<<prime<<", ";
    }
    cout<<endl;
}