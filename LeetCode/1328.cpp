// https://leetcode.com/problems/break-a-palindrome/

// Method 1 (2 Pointer, O(n)):

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        int p1 = 0, p2 = n-1;
        while(p1<p2){
            if(palindrome[p1] != 'a'){
                palindrome[p1] = 'a';
                return palindrome;
            }
            p1++;
            p2--;
        }
        if(n>1){
            palindrome[n-1] = 'b';
            return palindrome;
        }
        return "";
    }
};

// Method 2 (Iterative, O(n)):

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        for(int i = 0; i<n/2; i++){
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        for(int i = n-1; i>=(n+1)/2; i--){
            if(palindrome[i] != 'z'){
                palindrome[i]++;
                return palindrome;
            }
        }
        return "";
    }
};