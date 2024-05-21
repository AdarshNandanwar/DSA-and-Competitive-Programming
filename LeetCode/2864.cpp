// https://leetcode.com/problems/maximum-odd-binary-number/

// Method 1 (Counting Sort, O(n)):

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int onesToPrefix = -1;
        for(auto c:s){
            if(c == '1'){
                onesToPrefix++;
            }
        }
        int n = s.length();
        for(int i=0; i<onesToPrefix; i++){
            s[i] = '1';
        }
        for(int i=onesToPrefix; i<n; i++){
            s[i] = '0';
        }
        s[n-1] = '1';
        return s;
    }
};