// https://leetcode.com/problems/count-and-say/

// Method 1:

class Solution {
public:    
    string countAndSay(int n) {
        if(n == 1) return "1";
        string res = "", s = countAndSay(n-1);
        int count = 0;
        char prev = 0;
        for(auto & c:s){
            if(c == prev){
                count++;
            } else {
                if(prev != 0){
                    res += to_string(count);
                    res.push_back(prev);
                }
                prev = c;
                count = 1;
            }
        }
        res += to_string(count);
        res.push_back(prev);
        return res;
    }
};