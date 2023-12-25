// https://leetcode.com/problems/reverse-words-in-a-string-iii/

// Method 1 (Input String Stream):

class Solution {
public:
    string reverseWords(string s) {
        string word, res = "";
        istringstream iss(s);
        while(getline(iss, word, ' ')){
            reverse(word.begin(), word.end());
            res += word+" ";
        }
        res.pop_back();
        return res;
    }
};