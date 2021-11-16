// https://leetcode.com/problems/longest-duplicate-substring/

// Method 1 (Rabin Karp Rolling Hash Algorithm with Binary Search, Will give wrong answer when there is collision,
//           but less chance of collision by choosing prime number as base, O(nlogn)):

typedef unsigned long long ll;

class Solution {
public:
        
    /*
        Rabin-Karp Algorithm
        
        Q. Why this is working without MOD?
        Ans. Using unsigned data structures acts as doing MOD with ULLONG_MAX+1 
             and we don't have the problem of dealing with negative values after overflow.
        
        Q. Hash function collisions are also not being handled here. How is this working then?
        Ans. Choosing a prime as base greatly reduces the chance of collisions.
             Next greater prime after 26 is 29. Hence, choose this.
             If range of char is [0, 127] (full ascii range), choose 131 as base.
             
        Q. How to get correct answers always?
        Ans. Creating a map of [MOD hash] => {set of start indexes}.
             Add the start index to the set corresponding to the hash value.
             To confirm the existence, compare the substring if the hash matches.
    */
    
    vector<ll> mod_pow;
    ll base = 29;
    
    ll get_hash(const string & s, int index, int len){
        ll val = 0;
        while(len>0 and index<s.length()){
            val = val*base+(s[index]-'a');
            index++;
            len--;
        }
        return val;
    }
    
    bool is_valid(const string & s, int k, string & res){
        if(k == 0) {
            res = "";
            return true;
        }
        
        unordered_set<ll> hash_set;
        ll hash = get_hash(s, 0, k);
        hash_set.insert(hash);
        
        for(int i = k; i<s.length(); i++){
            // roll hash
            hash = hash-(s[i-k]-'a')*mod_pow[k-1];
            hash = hash*base;
            hash = hash+(s[i]-'a');            
            
            if(hash_set.count(hash)){
                res = s.substr(i-k+1, k);
                return true;
            }
            hash_set.insert(hash);
        }
        return false;
    }
    
    string longestDupSubstring(string s) {
        int n = s.length();
        
        mod_pow = vector<ll>(n, 1);
        for(int i = 1; i<n; i++) mod_pow[i] = base*mod_pow[i-1];
        
        // Binary Search
        // TF last T
        int lo = 0, hi = n-1, mid;
        string sub;
        while(lo<hi){
            mid = lo+(hi-lo+1)/2;
            if(is_valid(s, mid, sub)){
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        if(is_valid(s, lo, sub)) return sub;
        else return "";
    }
};

// Method 2 (Rabin Karp Rolling Hash Algorithm with Binary Search, Always gives the right answer, 
//           average case O(nlogn), worst case when lots of collisions O(n*n*logn),
//           TLE after passing all test cases):

typedef long long ll;
#define MOD 1000000007

class Solution {
public:
    
    vector<ll> mod_pow;
    
    ll get_hash(const string & s, int st, int len){
        ll val = 0, index = st;
        while(len>0 and index<s.length()){
            val = (val*26)%MOD;
            val = (val+(s[index]-'a'))%MOD;
            index++;
            len--;
        }
        return val;
    }
    
    bool is_valid(const string & s, int k, string & res){
        if(k == 0) {
            res = "";
            return true;
        }
        unordered_map<ll, unordered_set<int>> hash_to_index;
        ll hash = get_hash(s, 0, k);
        hash_to_index[hash].insert(0);
        
        for(int i = k; i<s.length(); i++){
            // roll hash
            hash = (hash-((ll)(s[i-k]-'a')*mod_pow[k-1])%MOD)%MOD;
            hash = (hash*26)%MOD;
            hash = (hash+(s[i]-'a'))%MOD;
            if(hash < 0) hash += MOD;       // IMPORTANT
            
            
            if(hash_to_index.count(hash)){
                string cur = s.substr(i-k+1, k), sub;
                for(auto &j:hash_to_index[hash]){
                    sub = s.substr(j, k);
                    if(cur == sub){
                        res = sub;
                        return true;
                    }
                }
            }
            hash_to_index[hash].insert(i-k+1);
        }
        return false;
    }
    
    string longestDupSubstring(string s) {
        int n = s.length();
        
        mod_pow = vector<ll>(n, 1);
        for(int i = 1; i<n; i++) mod_pow[i] = (26*mod_pow[i-1])%MOD;
        
        // Binary Search
        // TF last T
        int lo = 0, hi = n-1, mid;
        string sub;
        while(lo<hi){
            mid = lo+(hi-lo+1)/2;
            if(is_valid(s, mid, sub)){
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        if(is_valid(s, lo, sub)) return sub;
        else return "";
    }
};

// Method 3 (Binary Search, O(n*n*logn), TLE):

class Solution {
public:
    
    bool is_valid(const string & s, int k, string & res){
        if(k == 0){
            res = "";
            return true;
        }
        unordered_set<string> m;
        string sub = s.substr(0, k);
        m.insert(sub);
        for(int i = k; i<s.length(); i++){
            sub = sub.substr(1);
            sub.push_back(s[i]);
            if(m.count(sub)){
                res = sub;
                return true;
            } 
            m.insert(sub);
        }
        return false;
    }
    
    string longestDupSubstring(string s) {
        int n = s.length();
        // Binary Search
        // TF last T
        int lo = 0, hi = n-1, mid;
        string sub;
        while(lo<hi){
            mid = lo+(hi-lo+1)/2;
            if(is_valid(s, mid, sub)){
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        if(is_valid(s, lo, sub)) return sub;
        else return "";
    }
};