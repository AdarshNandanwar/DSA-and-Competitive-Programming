// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/

// Method 1 (2 Pointer, O(n)):

class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int left = 0, right = n-1;
        while(left < right){
            if(s[left] != s[right]){
                break;
            }
            char cur = s[left];
            left++;
            right--;
            while(left <= right and s[left] == cur){
                left++;
            }
            while(left <= right and s[right] == cur){
                right--;
            }
        }
        return right-left+1;
    }
};