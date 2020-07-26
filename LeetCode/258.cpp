// https://leetcode.com/problems/add-digits/

// Method 1 (String):

class Solution {
public:
    int addDigits(int num) {
        string s = to_string(num);
        int sum;
        while(s.length() != 1){
            sum = 0;
            for(auto c:s) sum += (c-'0');
            s = to_string(sum);
        }
        return stoi(s);
    }
};

// Method 2:

class Solution {
public:
    int addDigits(int num) {
        int sum = num;
        while(num/10 != 0){
            sum = 0;
            while(num){
                sum += (num%10);
                num /= 10;
            }
            num = sum;
        }
        return sum;
    }
};