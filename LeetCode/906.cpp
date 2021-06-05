// https://leetcode.com/problems/super-palindromes/

// Method 1 (Generate all valid palindromes):

typedef long long ll;

class Solution {
public:
    
    bool is_palindrome(string s){
        ll n = s.length();
        for(ll i = 0; i<n/2; i++){
            if(s[i] != s[n-1-i]) return false;
        }
        return true;
    }

    string next_palindrome(string s){
        ll n = s.length();
        
        for(ll i = (n-1)/2; i>=0; i--){
            if(s[i] == s[n-1-i]){
                continue;
            } else if(s[i] < s[n-1-i]){
                ll j;
                for(j = (n-1)/2; j>=0; j--){
                    if(s[j] != '9') break;
                }
                s[j]++;
                for(ll k = (n-1)/2; k>=0; k--){
                    s[n-1-k] = s[k];
                }
                return s;
            } else {
                for(ll j = i; j>=0; j--){
                    s[n-1-j] = s[j];
                }
                return s;
            }
        }
        return s;
    }

    string prev_palindrome(string s){
        ll n = s.length();
        if(s == "1") return "1";
        if(s == "1"+string(n-1, '0')) return string(n-1, '9');
        
        for(ll i = (n-1)/2; i>=0; i--){
            if(s[i] == s[n-1-i]){
                continue;
            } else if(s[i] < s[n-1-i]){
                for(ll j = i; j>=0; j--){
                    s[n-1-j] = s[j];
                }
                return s;
            } else {
                ll j;
                for(j = (n-1)/2; j>=0; j--){
                    if(s[j] != '0') break;
                }
                s[j]--;
                for(ll k = (n-1)/2; k>=0; k--){
                    s[n-1-k] = s[k];
                }
                return s;
            }
        }
        return s;
    }

    string make_even_palindrome(ll n){
        string s = to_string(n);
        ll l = s.length();
        for(ll i = l-1; i>=0; i--){
            s.push_back(s[i]);
        }
        return s;
    }

    string make_odd_palindrome(ll n){
        string s = to_string(n);
        ll l = s.length();
        for(ll i = l-2; i>=0; i--){
            s.push_back(s[i]);
        }
        return s;
    }

    ll superpalindromesInRange(string left, string right) {
        string temp;
        ll ans = 0, l = sqrt(stoll(left)), r = sqrt(stoll(right));
        left = next_palindrome(to_string(l));
        right = prev_palindrome(to_string(r));
        ll nl = left.length(), nr = right.length();
        
        for(ll i = nl; i<=nr; i++){             // length of the root palindrome
            ll k = (i+1)/2;                     // length of the first half of root palindrome
            ll st = pow(10, k-1), end = stoi(string(k, '9'));
            if(i == nl) st = max(st, stoll(left.substr(0, k)));
            if(i == nr) end = min(end, stoll(right.substr(0, k)));
            
            for(ll j = st; j<=end; j++){
                temp = i%2 ? make_odd_palindrome(j) : make_even_palindrome(j);
                ll sq = stoll(temp);
                sq = sq*sq;
                if(is_palindrome(to_string(sq))){
                    ans++;
                }
            }
        }
        return ans;
    }
};

// Method 2 (Cheating, O(1)):

typedef long long ll;

class Solution {
public:

    ll superpalindromesInRange(string left, string right) {
        vector<ll> v = {1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004, 100000020000001, 100220141022001, 102012040210201, 102234363432201, 121000242000121, 121242363242121, 123212464212321, 123456787654321, 400000080000004, 10000000200000001, 10002000300020001, 10004000600040001, 10020210401202001, 10022212521222001, 10024214841242001, 10201020402010201, 10203040504030201, 10205060806050201, 10221432623412201, 10223454745432201, 12100002420000121, 12102202520220121, 12104402820440121, 12122232623222121, 12124434743442121, 12321024642012321, 12323244744232321, 12343456865434321, 12345678987654321, 40000000800000004, 40004000900040004};
        ll l = stoll(left), r = stoll(right), ans = 0;
        for(auto &i:v) if(l<=i and i<=r) ans++;
        return ans;
    }
};