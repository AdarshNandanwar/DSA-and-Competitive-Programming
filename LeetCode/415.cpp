// https://leetcode.com/problems/add-strings/

class Solution {
public:
    string addStrings(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length(), carry = 0, sum = 0;
        int p1 = n1-1, p2 = n2-1;
        while(p1>=0 and p2>=0){
            sum = s1[p1]-'0' + s2[p2]-'0' + carry;
            carry = sum/10;
            s1[p1] = (sum%10)+'0';
            p1--; p2--;
        }
        while(p1>=0){
            sum = s1[p1]-'0' + carry;
            carry = sum/10;
            s1[p1] = (sum%10)+'0';
            p1--;
        }
        while(p2>=0){
            sum = s2[p2]-'0' + carry;
            carry = sum/10;
            s1 = to_string(sum%10)+s1;
            p2--;
        }
        if(carry) s1 = to_string(carry) + s1;
        return s1;
    }
};