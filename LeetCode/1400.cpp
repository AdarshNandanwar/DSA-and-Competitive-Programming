// https://leetcode.com/problems/construct-k-palindrome-strings/

// Method 1 (Freq Count, O(n)):

class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        int oddCount = 0;
        vector<int> freq(26);
        for(char c:s){
            freq[c-'a']++;
        }
        for(int i=0; i<26; i++){
            if(freq[i] % 2 == 1){
                oddCount++;
            }
        }
        return n >= k and oddCount <= k;
    }
};
