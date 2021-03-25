// https://leetcode.com/problems/valid-palindrome/

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