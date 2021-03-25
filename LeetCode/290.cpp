// https://leetcode.com/problems/word-pattern/

// Method 1 (Input String Stream):

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int n = pattern.length();
        istringstream iss(str);
        string w;
        unordered_map<string, char> m;
        unordered_set<char> mc;
        int index = 0;
        while(getline(iss, w, ' ')){
            if(index == n) return 0;
            if(m.count(w)){
                if(m[w] != pattern[index]) return 0;
            } else {
                if(mc.count(pattern[index])) return 0;
                m[w] = pattern[index];
                mc.insert(pattern[index]);
            }
            index++;
        }
        return index == n;
    }
};