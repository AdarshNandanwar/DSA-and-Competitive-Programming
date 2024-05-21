// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/

// Method 1 (O(n)):

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int startsWithZero = 0, startsWithOne = 0;
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                startsWithZero += (s[i] != '0');
                startsWithOne += (s[i] == '0');
            } else {
                startsWithZero += (s[i] == '0');
                startsWithOne += (s[i] != '0');
            }
        }
        return min(startsWithZero, startsWithOne);
    }
};