// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string A) {
        int open = 0, openAdded = 0;
        for(auto i:A){
            if(i == '('){
                open++;
            } else {
                if(open == 0) openAdded++;
                else open--;
            }
        }
        return openAdded+open;
    }
};