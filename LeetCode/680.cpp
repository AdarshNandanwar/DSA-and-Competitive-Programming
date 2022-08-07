// https://leetcode.com/problems/valid-palindrome-ii/

// Method 1 (2 Pointers, O(n)):

class Solution {
public:
    bool isPalindrome(const string & s, int st, int end){
        while(st<end){
            if(s[st] != s[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int n = s.length();
        int left = 0, right = n-1;
        while(left<right){
            if(s[left] == s[right]){
                left++;
                right--;
            } else {
               return isPalindrome(s, left+1, right) or isPalindrome(s, left, right-1);
            }
        }
        return true;
    }
};

// Method 2 (2 Pointer, O(n)):

class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length(), left, right, skipsRemaining;
        bool res;
        
        left = 0;
        right = n-1;
        skipsRemaining = 1;
        res = true;
        while(left<right){
            if(s[left] == s[right]){
                left++;
                right--;
            } else {
                if(skipsRemaining){
                    left++;
                    skipsRemaining--;
                } else {
                    res = false;
                    break;
                }
            }
        }
        if(res) return true;
        
        left = 0;
        right = n-1;
        skipsRemaining = 1;
        res = true;
        while(left<right){
            if(s[left] == s[right]){
                left++;
                right--;
            } else {
                if(skipsRemaining){
                    right--;
                    skipsRemaining--;
                } else {
                    res = false;
                    break;
                }
            }
        }
        return res;
    }
};