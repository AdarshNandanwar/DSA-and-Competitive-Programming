// https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/

// Method 1 (2 Pointers, O(n)):

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n1 =str1.length(), n2 = str2.length();
        int p1 = 0, p2 = 0;
        while(p1 < n1 and p2 < n2){
            if(str1[p1] == str2[p2] or (str1[p1]+1-'a')%26 == (str2[p2]-'a')%26){
                p2++;
            }
            p1++;
        }
        return p2 == n2;
    }
};
