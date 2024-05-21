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

// Alternate Code (Vectors, O(n)):

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> mapping(128, -1);
        vector<bool> used(128, false);
        int n = s.length();
        for(int i=0; i<n; i++){
            char c1 = s[i];
            char c2 = t[i];
            if(mapping[c1] == -1){
                if(!used[c2]){
                    mapping[c1] = c2;
                    used[c2] = true;
                } else {
                    return false;
                }
            } else {
                if(mapping[c1] == c2){
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
