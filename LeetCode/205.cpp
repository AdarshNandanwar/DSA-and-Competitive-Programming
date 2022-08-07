// https://leetcode.com/problems/isomorphic-strings/

// Method 1 (Hash map, O(n)):

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        unordered_map<char, char> mapping;
        unordered_set<char> mapped;
        for(int i=0; i<n; i++){
            if(mapping.count(s[i]) and t[i]!=mapping[s[i]]) return false;
            if(!mapping.count(s[i]) and mapped.count(t[i])) return false;
            mapping[s[i]] = t[i];
            mapped.insert(t[i]);
        }
        return true;
    }
};