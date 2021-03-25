// https://leetcode.com/problems/fraction-to-recurring-decimal/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans = "";
        if(numerator == 0){
            return "0";
        }
        if((numerator>0) != (denominator>0)){
            ans += "-";
        }
        numerator = abs(numerator);
        denominator = abs(denominator);
        long long int r = numerator%denominator, q = numerator/denominator;
        ans += to_string(q);
        
        if(r == 0){
            return ans;
        } else {
            ans += ".";            
        }
        
        string decimal = "", key = "";
        unordered_map<string, int> m;
        
        int index = 0;
        long long int num;
        while(r != 0){
            num = 10*r;
            q = num/denominator;
            r = num%denominator;
            key = to_string(q)+"/"+to_string(r);
            if(m.find(key) != m.end()){
                break;
            }
            m[key] = index;
            index++;
            decimal += to_string(q);
        }
        if(r == 0){
            return ans+decimal;
        } else {
            return ans+decimal.substr(0, m[key])+"("+decimal.substr(m[key])+")";
        }
    }
};