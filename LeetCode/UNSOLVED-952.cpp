// https://leetcode.com/problems/largest-component-size-by-common-factor/

// Attempt 2 (Union Find, TLE):

class Solution {
public:
    
    int maxSize = 1;
    
    void getPrimes(const int & n, set<int> & primes){
        vector<bool> isPrime(n+1, 1);
        int i;
        for(i = 2; i*i<=n; i++){
            if(!isPrime[i]) continue;
            primes.insert(i);
            for(int j = i*i; j<=n; j+=i) isPrime[j] = 0;
        }
        for(; i<=n; i++) if(isPrime[i]) primes.insert(i);
    }
    
    int root(int x, vector<int> & id){
        if(x == id[x]) return x;
        return id[x] = root(id[x], id);
    }
    
    void merge(int r1, int r2, vector<int> & id, vector<int> & sz){
        if(sz[r1] < sz[r2]) swap(r1, r2);
        id[r2] = r1;
        sz[r1] += sz[r2];
        maxSize = max(maxSize, sz[r1]);
    }
    
    int largestComponentSize(vector<int>& A) {
        int n = A.size(), maxEle = *max_element(A.begin(), A.end());
        vector<int> id(n), sz(n, 1);
        for(int i = 0; i<n; i++) id[i] = i;
        
        set<int> primes;
        // generating primes till maxElement
        getPrimes(maxEle, primes);
        
        int first, r1, r2;
        unordered_map<int, int> firstIndexOfPrime;
        
        for(int i = 0; i<n; i++){
            for(auto p:primes){
                if(p>A[i]) break;
                if(A[i]%p == 0){
                    if(firstIndexOfPrime.count(p)){
                        r1 = root(firstIndexOfPrime[p], id), r2 = root(i, id);
                        if(r1 != r2) merge(r1, r2, id, sz);
                    } else {
                        firstIndexOfPrime[p] = i;
                    }
                } 
            }
        }
        return maxSize;
    }
};

// Attempt 1 (Union Find, TLE):

class Solution {
public:
    
    int maxSize = 1;
    
    void getPrimes(const int & n, unordered_set<int> & primes){
        vector<bool> isPrime(n+1, 1);
        int i;
        for(i = 2; i*i<=n; i++){
            if(!isPrime[i]) continue;
            primes.insert(i);
            for(int j = i*i; j<=n; j+=i) isPrime[j] = 0;
        }
        for(; i<=n; i++) if(isPrime[i]) primes.insert(i);
    }
    
    int root(int x, vector<int> & id){
        if(x == id[x]) return x;
        return id[x] = root(id[x], id);
    }
    
    void merge(int r1, int r2, vector<int> & id, vector<int> & sz){
        if(sz[r1] < sz[r2]) swap(r1, r2);
        id[r2] = r1;
        sz[r1] += sz[r2];
        maxSize = max(maxSize, sz[r1]);
    }
    
    int largestComponentSize(vector<int>& A) {
        int n = A.size(), maxEle = *max_element(A.begin(), A.end());
        vector<int> id(n), sz(n, 1);
        for(int i = 0; i<n; i++) id[i] = i;
        
        unordered_set<int> primes;
        // generating primes till maxElement
        getPrimes(maxEle, primes);
        
        int first, r1, r2;
        // making the first multiple the root of all other multiples
        for(auto p:primes){
            first = -1;
            for(int i = 0; i<n; i++){
                if(A[i]%p == 0){
                    if(first == -1){
                        first = i;
                    } else {
                        r1 = root(first, id), r2 = root(i, id);
                        if(r1 != r2) merge(r1, r2, id, sz);
                    }
                } 
            }
        }
        return maxSize;
    }
};