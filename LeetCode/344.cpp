// https://leetcode.com/problems/reverse-string/

// Method 1 (STL, O(n)):

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};

// Method 2 (2 Pointer, O(n)):

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0, j=s.size()-1;
        while(i<j){
            swap(s[i++], s[j--]);
        }
    }
};