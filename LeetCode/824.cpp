// https://leetcode.com/problems/goat-latin/

// Method 1 (input string stream, O(n)):

class Solution {
public:
    string toGoatLatin(string s) {
        string res = "", w, vowels = "aeiouAEIOU";
        istringstream iss(s);
        int ind = 1;
        while(getline(iss, w, ' ')){
            if(w.length() == 0) continue;
            if(count(vowels.begin(), vowels.end(), w[0])) w += "ma";
            else w = w.substr(1)+w[0]+"ma";
            res += (" " + w + string(ind++, 'a'));
        }
        return res.substr(1);
    }
};