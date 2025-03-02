// https://leetcode.com/problems/string-compression-iii/

// Method 1 (Loop, O(n)):

class Solution {
public:
    string compressedString(string word) {
        int n = word.length();

        string compressedString;
        int curCount = 1;
        for(int i=1; i<n; i++){
            if(word[i] == word[i-1] and curCount < 9){
                curCount++;
            } else {
                compressedString += to_string(curCount);
                compressedString += word[i-1];
                curCount = 1;
            }
        }
        compressedString += to_string(curCount);
        compressedString += word[n-1];

        return compressedString;
    }
};
