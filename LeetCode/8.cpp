// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string str) {
        long n = str.length(), res = 0, i = 0;
        while(i<n and str[i] == ' ') i++;
        bool isPos = 1;
        if(i<n and str[i] == '-'){
            isPos = 0;
            i++;
        } else if(i<n and str[i] == '+'){
            isPos = 1;
            i++;
        } 
        while(i<n and isdigit(str[i])){
            res = res*10+(str[i]-'0');
            if(isPos and res>INT_MAX) return INT_MAX;
            if(!isPos and -res<INT_MIN) return INT_MIN;
            i++;
        }
        return isPos ? res : -res;
    }
};