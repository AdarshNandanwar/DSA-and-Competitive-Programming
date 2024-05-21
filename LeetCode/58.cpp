// https://leetcode.com/problems/length-of-last-word/

// Method 1 (Loop, O(n)):

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int endIndex = n-1;
        while(endIndex>=0){
            if(s[endIndex] != ' '){
                break;
            }
            endIndex--;
        }
        int startIndex = endIndex-1;
        while(startIndex>=0){
            if(s[startIndex] == ' '){
                break;
            }
            startIndex--;
        }
        return endIndex-startIndex;
    }
};

// Method 2 (Input string stream, O(n)):

class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream iss(s);
        string w;
        int res = 0;
        while(getline(iss, w, ' ')) if(w.length()) res = w.length();
        return res;
    }
};
