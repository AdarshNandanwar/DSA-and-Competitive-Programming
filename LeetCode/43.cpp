// https://leetcode.com/problems/multiply-strings/

// Method 1 (Multiply at once, O(n*m)):

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

// Method 2 (Multiply one by one and add strings, O(n*m)):

class Solution {
public:
    string addition(string s1, string s2){
        int n1 = s1.length(), n2 = s2.length();
        int p1 = n1-1, p2=n2-1;
        int carry = 0, sum = 0;
        string res;
        while(p1>=0 and p2>=0){
            sum = s1[p1]-'0'+s2[p2]-'0'+carry;
            carry = sum/10;
            sum = sum%10;
            res.push_back(sum+'0');
            p1--;
            p2--;
        }
        while(p1>=0){
            sum = s1[p1]-'0'+carry;
            carry = sum/10;
            sum = sum%10;
            res.push_back(sum+'0');
            p1--;
        }
        while(p2>=0){
            sum = s2[p2]-'0'+carry;
            carry = sum/10;
            sum = sum%10;
            res.push_back(sum+'0');
            p2--;
        }
        if(carry){
            res.push_back(carry+'0');
        }
        return string(res.rbegin(), res.rend());
    }
    
    string multiply(string num1, string num2) {
        if(num1=="0" or num2=="0") return "0";
        int n1= num1.size(), n2 = num2.size();
        string ans = string(n1+n2, '0');
        for(int i=n2-1; i>=0; i--){
            int zeros = n2-1-i;
            int sum = 0, carry = 0;
            string toAdd(n1+1+zeros, '0');
            for(int j=n1-1; j>=0; j--){
                int prod = (num2[i]-'0')*(num1[j]-'0');
                sum = prod+carry;
                carry = sum/10;
                toAdd[j+1] = (sum%10)+'0';
            }
            toAdd[0] = carry+'0';
            ans = addition(ans, toAdd);
        }
        int start=0;
        while(start<n1+n2){
            if(ans[start] != '0'){
                break;
            }
            start++;
        }
        return ans.substr(start);
    }
};