// https://leetcode.com/problems/length-of-last-word/

// Method 1 (input string stream, o(n)):

class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream iss(s);
        string w;
        int res = 0;
        while(getline(iss, w, ' ')) if(w.length()) res = w.length();
        return res;
    }
};