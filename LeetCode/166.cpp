// https://leetcode.com/problems/fraction-to-recurring-decimal/

// Method 1:

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0){
            return "0";
        }
        bool sign = (numerator>=0) == (denominator>=0);
        long num = abs((long)numerator), den = abs((long)denominator);
        long wholePart = num/den;
        string ans = to_string(wholePart);
        long remainder = num%den;
        if(remainder == 0){
            if(sign){
                return ans;
            } else {
                return "-"+ans;
            }
        } 
        ans.push_back('.');
        vector<long> decimal;
        unordered_map<long, long> index;
        while(remainder){
            if(index.count(remainder)){
                break;    
            }
            index[remainder] = decimal.size();
            long quotient = (10*remainder)/den;
            remainder = (10*remainder)%den;
            decimal.push_back(quotient);
        }
        if(remainder){
            for(int i=0; i<index[remainder]; i++){
                ans.push_back('0'+decimal[i]);
            }
            ans.push_back('(');
            for(int i=index[remainder]; i<decimal.size(); i++){
                ans.push_back('0'+decimal[i]);
            }
            ans.push_back(')');
        } else {
            for(int i=0; i<decimal.size(); i++){
                ans.push_back('0'+decimal[i]);
            }
        }
        if(sign){
            return ans;
        } else {
            return "-"+ans;
        }
    }
};