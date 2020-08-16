// https://leetcode.com/problems/longest-palindrome/

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