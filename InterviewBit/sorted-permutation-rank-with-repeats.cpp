// https://www.interviewbit.com/problems/sorted-permutation-rank-with-repeats/

// Method 1 (Math, Inverse Modulo):

#define MOD 1000003
typedef long long ll;


/* CODE FOR INVERSE MODULO I.E. MODULO FOR DIVISION */

// C function for extended Euclidean Algorithm 
ll gcdExtended(ll a, ll b, ll *x, ll *y); 
  
// Function to find modulo inverse of b. It returns 
// -1 when inverse doesn't 
ll modInverse(ll b, ll m) 
{ 
    ll x, y; // used in extended GCD algorithm 
    ll g = gcdExtended(b, m, &x, &y); 
  
    // Return -1 if b and m are not co-prime 
    if (g != 1) 
        return -1; 
  
    // m is added to handle negative x 
    return (x%m + m) % m; 
} 
  
// Function to compute a/b under modlo m 
ll modDivide(ll a, ll b, ll m) 
{ 
    a = a % m; 
    ll inv = modInverse(b, m); 
    if (inv == -1) 
       return -1;
    else
       return (inv * a) % m; 
} 
  
// C function for extended Euclidean Algorithm (used to 
// find modular inverse. 
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; // To store results of recursive call 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

/* CODE FOR INVERSE MODULO ENDS HERE */




vector<ll> dp;

ll fact(ll n){
    if(n <= 1) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = (n*fact(n-1))%MOD;
}

ll helper(map<char, ll> & m, char c){
    m[c]--;
    ll den = 1, count = 0;
    for(auto itr = m.begin(); itr !=m.end(); itr++){
        count = (count + itr->second)%MOD;
        den = (den * fact(itr->second))%MOD;
    } 
    m[c]++;
    return modDivide(fact(count), den, MOD);
}

int Solution::findRank(string A) {
    ll n = A.length();
    dp = vector<ll>(n+1, -1);
    map<char, ll> m;
    for(auto i:A) m[i]++;
    
    ll res = 1;
    for(auto i:A){
        ll den = 1, distinctCount = 0, count = 0;
        for(auto itr = m.begin(); itr !=m.end() and itr->first<i; itr++){
            res = (res + helper(m, itr->first))%MOD;
        } 
        m[i]--;
        if(m[i] == 0) m.erase(i);
    }
    return res;
}
