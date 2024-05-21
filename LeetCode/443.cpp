// https://leetcode.com/problems/string-compression/description/

// Method 1 (Loop, O(n) time, O(1) space):

class Solution {
public:
    int compress(vector<char>& chars) {
        int writeIndex = 0;
        char cur = chars[0];
        int curFreq = 0;
        for(int i=0; i<chars.size(); i++){
            if(chars[i] == cur){
                curFreq++;
            } else {
                chars[writeIndex++] = cur;
                if(curFreq > 1){
                    for(char c:to_string(curFreq)){
                        chars[writeIndex++] = c;
                    }
                }
                cur = chars[i];
                curFreq = 1;
            }
        }
        chars[writeIndex++] = cur;
        if(curFreq > 1){
            for(char c:to_string(curFreq)){
                chars[writeIndex++] = c;
            }
        }
        return writeIndex;
    }
};

// Method 2 (Loop, O(n) time, O(n) space):

class Solution {
    string getCompressedString(char c, int freq){
        if(freq == 0){
            return "";
        } else if(freq == 1){
            return string(1, c);
        } else {
            return string(1, c) + to_string(freq);
        }
    }
public:
    int compress(vector<char>& chars) {
        char cur = chars[0];
        int curFreq = 0;
        string compressedString;
        for(int i=0; i<chars.size(); i++){
            if(chars[i] == cur){
                curFreq++;
            } else {
                compressedString += getCompressedString(cur, curFreq);
                cur = chars[i];
                curFreq = 1;
            }
        }
        compressedString += getCompressedString(cur, curFreq);
        for(int i=0; i<compressedString.length(); i++){
            chars[i] = compressedString[i];
        }
        return compressedString.length();
    }
};