// https://leetcode.com/problems/plus-one/

// Method 1 (O(n)):

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1, sum = 0;
        for(int i=n-1; i>=0; i--){
            sum = digits[i]+carry;
            digits[i] = sum%10;
            carry = sum/10;
        }
        if(carry){
            digits.push_back(0);
            for(int i=n-1; i>=0; i--){
                digits[i+1] = digits[i];
            }
            digits[0] = carry;
        }
        return digits;
    }
};

// Method 2 (O(n)):

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), i;
        for(i = n-1; i>=0; i--){
            if(digits[i] != 9){
                digits[i]++;
                break;
            } else {
                digits[i] = 0;
            }
        }
        if(i == -1) digits.insert(digits.begin(), 1);
        return digits;
    }
};