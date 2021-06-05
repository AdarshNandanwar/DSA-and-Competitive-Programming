// https://leetcode.com/problems/find-and-replace-pattern/

// Method 1 (Set):

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto & w:words){
            bool is_valid = true;
            unordered_map<char, char> m;
            unordered_set<char> s;
            for(int i = 0; i<w.length(); i++){
                if(m.count(pattern[i])){
                    if(m[pattern[i]] != w[i]){
                        is_valid = false;
                        break;
                    }
                } else {
                    if(s.count(w[i])){
                        is_valid = false;
                        break;
                    } else {
                        m[pattern[i]] = w[i];
                        s.insert(w[i]);
                    }
                }
            }
            if(is_valid) ans.push_back(w);
        }
        return ans;
    }
};

// Method 2 (Reverse Map):

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto & w:words){
            bool is_valid = true;
            unordered_map<char, char> m, rev_m;
            for(int i = 0; i<w.length(); i++){
                if(m.count(pattern[i]) and rev_m.count(w[i])){
                    if(m[pattern[i]] != w[i] or rev_m[w[i]] != pattern[i]){
                        is_valid = false;
                        break;
                    }
                } else if(m.count(pattern[i]) or rev_m.count(w[i])){
                    is_valid = false;
                    break;
                } else {
                    m[pattern[i]] = w[i];
                    rev_m[w[i]] = pattern[i];
                }
            }
            if(is_valid) ans.push_back(w);
        }
        return ans;
    }
};
