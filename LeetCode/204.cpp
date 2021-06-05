// https://leetcode.com/problems/count-primes/

// Method 1 (Sieve of Erastosthenes):

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> sieve(n, true);
        int end = sqrt(n), ans = 0;
        
        for(int i = 2; i<n; i++){
            if(i<=end and sieve[i]){
                for(int j = i*i; j<n; j+=i){
                    sieve[j] = false;
                }
            }
            ans += sieve[i];
        }
        return ans;
    }
};

// Alternate Code

class Solution {
public:
    int countPrimes(int n) {
        if(n<=1) return 0;
        vector<bool> v(n, 1);       // isPrime?
        v[0] = v[1] = 0;
        for(int i = 2; i*i<n; i++){
            if(v[i]){
                for(int j = 2*i; j<n; j+=i){
                    v[j] = 0;
                }
            }
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};