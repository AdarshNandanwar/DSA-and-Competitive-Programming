// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/

// Method 1 (2 Pointer, O(n*len)):

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string res;
        for(const string& word:words){
            int start = 0, end = word.length()-1;
            while(start<end){
                if(word[start] != word[end]){
                    break;
                }
                start++;
                end--;
            }
            if(start>=end){
                return word;
            }
        }
        return "";
    }
};
