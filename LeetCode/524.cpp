// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/

// Method 1 (Sorting, O(klogk+k(n+m))):

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](const string & a, const string & b){
            return a.length() == b.length() ? a<b : a.length() > b.length();
        });
        int n = s.length();
        for(auto &word:dictionary){
            int m = word.length();
            int p1 = 0, p2 = 0;
            while(p1<n and p2<m){
                if(s[p1] == word[p2]){
                    p2++;
                }
                p1++;
            }
            if(p2 == m) return word;
        }
        return "";
    }
};