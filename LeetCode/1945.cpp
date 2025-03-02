// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/

// Method 1 (Strings, O(n)):

class Solution {
public:
    int getLucky(string s, int k) {
        string digitString;
        for(char c:s){
            digitString += to_string(c-'a'+1);
        }

        int digitSum = 0;
        for(char c:digitString){
            digitSum += (c-'0');
        }

        k--;
        while(k--){
            int temp = 0;
            while(digitSum){
                temp += (digitSum % 10);
                digitSum /= 10;
            }
            digitSum = temp;
        }
        
        return digitSum;
    }
};

// Method 2 (Strings, O(n)):

class Solution {
public:
    int getLucky(string s, int k) {
        string digitString;
        for(char c:s){
            digitString += to_string(c-'a'+1);
        }
        
        string transformedString = digitString;
        while(k--){
            int sum = 0;
            for(char c:transformedString){
                sum += (c-'0');
            }
            transformedString = to_string(sum);
        }
        
        return stoi(transformedString);
    }
};
