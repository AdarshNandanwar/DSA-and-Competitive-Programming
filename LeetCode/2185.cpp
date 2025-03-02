// https://leetcode.com/problems/counting-words-with-a-given-prefix/

// Method 1 (Loops, O(n+m)):

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.length();
        int count = 0;
        for(const string & word:words){
            if(word.length() < n){
                continue;
            }
            int i=0;
            while(i<n){
                if(word[i] != pref[i]){
                    break;
                }
                i++;
            }
            if(i == n){
                count++;
            }
        }
        return count;
    }
};
