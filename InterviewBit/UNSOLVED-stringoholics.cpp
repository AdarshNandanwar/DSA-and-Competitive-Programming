// https://www.interviewbit.com/problems/stringoholics/

// Attempt 2 (Using LCM function from GFG, TLE, O(n)):

#define mod 1000000007
#define MAX 10000003 
#define F first 
#define S second 
typedef long long int ll;

int prime[MAX]; 
unordered_map<int, int> max_map; 
  
// Function to return a^n 
int power(int a, int n) 
{ 
    if (n == 0) 
        return 1; 
    int p = power(a, n / 2) % mod; 
    p = (p * p) % mod; 
    if (n & 1) 
        p = (p * a) % mod; 
    return p; 
} 
  
// Function to find the smallest prime factors 
// of numbers upto MAX 
void sieve() 
{ 
    prime[0] = prime[1] = 1; 
    for (int i = 2; i < MAX; i++) { 
        if (prime[i] == 0) { 
            for (int j = i * 2; j < MAX; j += i) { 
                if (prime[j] == 0) { 
                    prime[j] = i; 
                } 
            } 
            prime[i] = i; 
        } 
    } 
} 
  
// Function to return the LCM modulo M 
ll lcmModuloM(const vector<ll> ar) 
{ 
    ll n = ar.size();
    for (int i = 0; i < n; i++) { 
        int num = ar[i]; 
        unordered_map<int, int> temp; 
  
        // Temp stores mapping of prime factor to 
        // its power for the current element 
        while (num > 1) { 
  
            // Factor is the smallest prime factor of num 
            int factor = prime[num]; 
  
            // Increase count of factor in temp 
            temp[factor]++; 
  
            // Reduce num by its prime factor 
            num /= factor; 
        } 
  
        for (auto it : temp) { 
  
            // Store the highest power of every prime 
            // found till now in a new map max_map 
            max_map[it.first] = max(max_map[it.first], it.second); 
        } 
    } 
  
    ll ans = 1; 
  
    for (auto it : max_map) { 
  
        // LCM is product of primes to their highest powers modulo M 
        ans = (ans * power(it.F, it.S)) % mod; 
    } 
  
    return ans; 
} 

vector<ll> getLps(const string & s){
    ll n = s.length();
    vector<ll> lps(n, 0);
    ll i = 1, j = lps[i-1];
    while(i < n){
        if(s[i] == s[j]){
            lps[i] = j+1;
            i++;
            j = lps[i-1];
        } else {
            if(j == 0){
                lps[i] = 0;
                i++;
                j = lps[i-1];
            } else {
                j = lps[j-1];
            }
        }
    }
    return lps;
}

int Solution::solve(vector<string> &A) {
    ll res = 0;
    vector<ll> times;
    for(auto s:A){
        ll n = s.length();
        if(n == 0) continue;
        auto lps = getLps(s);
        ll len = n-lps[n-1];
        ll repeatLen = n%len ? n : len;
        ll st = 0, time = 0;
        do{
            time++;
            st = (st+time)%n;
        } while(st%repeatLen);
        times.push_back(time);
    }
    sieve();
    return lcmModuloM(times);
}

// Attempt 1 (WA on submit, probabily because of MOD, O(n)):

#define MOD 1000000007
typedef long long int ll;

vector<bool> getPrimes(ll m){
    vector<bool> isPrime(m+1, 1);
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 2; i*i<=m; i++){
        if(isPrime[i]){
            for(ll j = i*i; j<=m; j+=i){
                isPrime[j] = 0;
            }
        }
    }
    return isPrime;
}

vector<ll> getLps(const string & s){
    ll n = s.length();
    vector<ll> lps(n, 0);
    ll i = 1, j = lps[i-1];
    while(i < n){
        if(s[i] == s[j]){
            lps[i] = j+1;
            i++;
            j = lps[i-1];
        } else {
            if(j == 0){
                lps[i] = 0;
                i++;
                j = lps[i-1];
            } else {
                j = lps[j-1];
            }
        }
    }
    return lps;
}

ll getLcm(vector<ll> & v){
    ll n = v.size();
    if(n == 0) return 1;
    ll res = 1;
    unordered_map<ll, ll> maxFreq;
    auto isPrime = getPrimes(10e5);
    for(auto i:v){
        if(i <= 1) continue;
        ll fact = 2, freq;
        while(i != 1){
            while(!isPrime[fact]) fact++;
            freq = 0;
            while(i%fact == 0){
                freq++;
                i/=fact;
            }
            if(freq) maxFreq[fact] = max(maxFreq[fact], freq);
            fact++;
        }
    } 
    for(auto [i, j]:maxFreq) res = (res*((i*j)%MOD))%MOD;
    return res;
}

int Solution::solve(vector<string> &A) {
    ll res = 0;
    vector<ll> times;
    for(auto s:A){
        ll n = s.length();
        if(n == 0) continue;
        auto lps = getLps(s);
        ll len = n-lps[n-1];
        ll repeatLen = n%len ? n : len;
        ll st = 0, time = 0;
        do{
            time++;
            st = (st+time)%n;
        } while(st%repeatLen);
        times.push_back(time);
    }
    return getLcm(times);
}
