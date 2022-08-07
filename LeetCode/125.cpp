// https://leetcode.com/problems/valid-palindrome/

// Method 1 (2 Pointer, O(n)):

class Solution {
public:
    bool isPalindrome(string s) {
        string palindrome = "";
        for(auto &c:s){
            if(isalnum(c)){
                palindrome.push_back(tolower(c));
            }
        }
        int lo = 0, hi = palindrome.length()-1;
        while(lo<hi){
            if(palindrome[lo] != palindrome[hi]){
                return false;
            }
            lo++;
            hi--;
        }
        return true;
    }
};

// Alternate Code:

class Solution {
public:
    bool isPalindrome(string s) {
        int l = s.length(), p1 = 0, p2 = l-1;
        while(p1<p2){
            while(p1<p2 and !isalnum(s[p1])) p1++;
            while(p1<p2 and !isalnum(s[p2])) p2--;
            if(p1<p2 and tolower(s[p1]) != tolower(s[p2])) return 0;
            p1++; p2--;
        }
        return 1;
    }
};