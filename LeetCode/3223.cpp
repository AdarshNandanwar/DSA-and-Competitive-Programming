// https://leetcode.com/problems/minimum-length-of-string-after-operations/

// Method 1 (Frequency, O(n)):

class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26);
        for(char c:s){
            freq[c-'a']++;
        }
        
        int minLen = 0;
        for(int i=0; i<26; i++){
            if(freq[i] == 0){
                continue;
            } else if(freq[i] % 2 == 0){
                minLen += 2;
            } else {
                minLen += 1;
            }
        }

        return minLen;
    }
};

// Method 2 (Single loop, O(n)):

class Solution {
public:
    int minimumLength(string s) {
        int minLen = 0;
        vector<int> freq(26);
        for(char c:s){
            freq[c-'a']++;
            if(freq[c-'a'] == 1){
                minLen += 1;
            } else if(freq[c-'a'] % 2 == 1){
                minLen -= 1;
            } else {
                minLen += 1;
            }
        }
        return minLen;
    }
};
