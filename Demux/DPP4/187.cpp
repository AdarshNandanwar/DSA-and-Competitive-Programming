// https://leetcode.com/problems/repeated-dna-sequences/

// Method 1 (Hash Map with int key, O(n)):

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        vector<string> ans;
        if(n<10) return ans;
        unordered_map<int, int> m;
        
        // last 3 bits of ASCII codes of A, T, C, G are different
        int key = 0;
        m[key]++;
        for(int i = 0; i<n; i++){
            key = (((key & 0x7ffffff) << 3) | (s[i] & 7));
            m[key]++;
            if(m[key] == 2) ans.push_back(s.substr(i-9, 10));
        }
        return ans;
    }
};

// Method 2 (Hash Map with string key, O(10*n)):

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        vector<string> ans;
        if(n<10) return ans;
        unordered_map<string, int> m;
        string cur;
        for(int i = 0; i+9<n; i++){
            cur = s.substr(i,10);
            m[cur]++;
            if(m[cur] == 2) ans.push_back(cur);
        }
        return ans;
    }
};