// https://leetcode.com/problems/break-a-palindrome/

// Method 1 (O(n)):

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