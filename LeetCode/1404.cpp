// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

// Method 1 (Bit Manipulation, O(n*n)):

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        
        while(s != "1"){
            if(s.back() == '1'){
                int n = s.length();
                int i = n-1;
                while(i>=0 and s[i] == '1'){
                    s[i] = '0';
                    i--;
                }
                if(i < 0){
                    // all ones
                    return steps + 1 + s.length();
                }
                s[i] = '1';
                steps++;
            }
            s.pop_back();
            steps++;
        }

        return steps;
    }
};
