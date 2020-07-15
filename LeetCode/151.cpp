// https://leetcode.com/problems/reverse-words-in-a-string/

// Method 1 (InputStringStream):

class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string cur, ans ="";
        while(getline(iss, cur, ' ')){
            if(cur.length() == 0) continue;
            if(ans.length() == 0) ans = cur;
            else ans = cur+" "+ans;
        }
        return ans;
    }
};