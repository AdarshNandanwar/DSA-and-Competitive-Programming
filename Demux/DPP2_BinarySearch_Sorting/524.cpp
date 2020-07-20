// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](const string & a, const string & b){
            if(a.length() != b.length()) return a.length()>b.length();
            else return a<b;
        });
        for(auto word:d){
            int i = 0;
            for(auto c:s){
                if(c == word[i]) i++;
                if(i == word.length()) return word;
            }
        }
        return "";
    }
};