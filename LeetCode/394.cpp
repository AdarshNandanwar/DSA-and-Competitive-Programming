// https://leetcode.com/problems/decode-string/

// Method 1 (Recursion, O(n2)):

class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        int bracketLevel = 0, baseOpen = -1;
        string res = "";
        for(int i=0; i<n; i++){
            if(s[i] == '['){
                if(bracketLevel == 0){
                    baseOpen = i;
                }
                bracketLevel++;
            } else if(s[i] == ']'){
                bracketLevel--;
                if(bracketLevel == 0){
                    int digitBegin = baseOpen-1;
                    while(digitBegin>=0 and isdigit(s[digitBegin])){
                        digitBegin--;
                    }
                    digitBegin++;
                    int count = stoi(s.substr(digitBegin, baseOpen-digitBegin));

                    string toRepeat = decodeString(s.substr(baseOpen+1, i-baseOpen-1));
                    
                    while(count--){
                        res += toRepeat;
                    }
                }
            } else if(bracketLevel == 0 and isalpha(s[i])){
                res += string(1, s[i]);
            }
        }
        return res;
    }
};