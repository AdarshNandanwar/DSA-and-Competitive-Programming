// https://leetcode.com/problems/separate-black-and-white-balls/

// Method 1 (Counting, O(n)):

class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        int zeros = 0;
        for(char c:s){
            if(c == '0'){
                zeros++;
            }
        }

        long long steps = 0;
        int curZeros = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '0'){
                curZeros++;
            } else {
                int zerosOnright = zeros - curZeros;
                steps += zerosOnright;
            }
        }

        return steps;
    }
};
