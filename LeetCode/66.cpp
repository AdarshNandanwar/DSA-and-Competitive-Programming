// https://leetcode.com/problems/plus-one/

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