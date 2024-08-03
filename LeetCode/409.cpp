// https://leetcode.com/problems/longest-palindrome/

// Method 1 (Hash Map, O(n) time, O(1) space):

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(128);
        
        int palindromeLength = 0;
        for(char c:s){
            freq[c]++;
            if(freq[c] % 2 == 0){
                palindromeLength += 2;
            }
        }

        bool oddPresent = false;
        for(int i=0; i<128; i++){
            if(freq[i] % 2 == 1){
                oddPresent = true;
            }
        }
        return palindromeLength + oddPresent;
    }
};

// Alternate Code:

class Solution {
public:
    int longestPalindrome(string s) {
        int len = 0;
        unordered_map<char, int> freq;
        for(auto c:s) freq[c]++;
        bool oddPresent = 0;
        for(auto [i, f]:freq){
            if(f%2) oddPresent = 1;
            len += ((f/2)*2);
        }
        return len+oddPresent;
    }
};
