// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/

// Method 1 (Loops, O(n)):

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<int> firstOccurence(26, n), lastOccurence(26, -1);
        for(int i=0; i<n; i++){
            firstOccurence[s[i]-'a'] = min(firstOccurence[s[i]-'a'], i);
            lastOccurence[s[i]-'a'] = max(lastOccurence[s[i]-'a'], i);
        }
        
        int subsequenceCount = 0;
        for(int i=0; i<26; i++){
            unordered_set<char> charsInBetween;
            for(int j=firstOccurence[i]+1; j<lastOccurence[i]; j++){
                charsInBetween.insert(s[j]);
            }
            subsequenceCount += charsInBetween.size();
        }
        return subsequenceCount;
    }
};
