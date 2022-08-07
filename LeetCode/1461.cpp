// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

// Method 1 (Rolling Hash, O(1) to calculate next hash, O(n)):

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        int cur = 0;
        for(int i=0; i<min(n, k-1); i++){
            cur <<= 1;
            cur |= (s[i] == '1');
        }
        unordered_set<int> found;
        for(int i=k-1; i<n; i++){
            cur <<= 1;
            cur |= (s[i] == '1');
            cur &= ((1<<k)-1);
            found.insert(cur);
        }
        return found.size() == (1<<k);
    }
};

// Method 2 (Substring, O(n*k)):

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        unordered_set<string> found;
        for(int i=0; i<n-k+1; i++){
            found.insert(s.substr(i, k));
        }
        return found.size() == (1<<k);
    }
};