// https://leetcode.com/problems/multiply-strings/

// Method 1 (Multiply at once, O(n2)):

class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.length(), l2 = num2.length(), carry, digit;
        string prod(l1+l2, '0');
        for(int i = l1-1; i>=0; i--){
            for(int j = l2-1; j>=0; j--){
                int temp = prod[i+j+1]-'0'+(num1[i]-'0')*(num2[j]-'0')+carry;
                carry = temp/10;
                prod[i+j+1] = '0'+temp%10;
            }
            if(carry) prod[i] = '0'+carry;
            carry = 0;
        }
        int idx = 0;
        while(idx<prod.length()){
            if(prod[idx] != '0') return prod.substr(idx);
            idx++;
        }
        return "0";
    }
};

// Method 2 (Multiply one by one and add strings, O(n2)):

void addString(string & s1, string & s2){
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
}

class Solution {
public:
    string multiply(string s1, string s2) {
        if(s1 == "0" or s2 == "0") return "0";
        int n1 = s1.length(), n2 = s2.length(), carry, p, a, b, k;
        string prod = "0";
        for(int i = n2-1; i>=0; i--){
            string temp = string(n2-1-i, '0');
            carry = 0;
            a = s2[i]-'0';
            for(int j = n1-1; j>=0; j--){
                b = s1[j]-'0';
                p = a*b+carry;
                carry = p/10;
                temp = to_string(p%10)+temp;
            }
            if(carry) temp = to_string(carry)+temp;
            addString(prod, temp);
        }
        for(k = 0; k<prod.length(); k++) if(prod[k] != '0') break;
        if(k == prod.length()) prod = "0";
        else if(k != 0) prod = prod.substr(k, prod.length()-k);
        return prod;
    }
};