// https://leetcode.com/problems/reverse-only-letters/

// Method 1 (2 Pointer, O(n)):

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.length();
        int p1 = 0, p2 = n-1;
        while(p1<p2){
            while(p1<p2 and !(('a'<=s[p1] and s[p1]<='z') or ('A'<=s[p1] and s[p1]<='Z'))) p1++;
            while(p1<p2 and !(('a'<=s[p2] and s[p2]<='z') or ('A'<=s[p2] and s[p2]<='Z'))) p2--;
            swap(s[p1++], s[p2--]);
        }
        return s;
    }
};