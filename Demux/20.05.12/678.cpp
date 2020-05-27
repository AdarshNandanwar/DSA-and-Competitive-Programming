// https://leetcode.com/problems/valid-parenthesis-string/

class Solution {
public:
    bool checkValidString(string s) {
        int diff = 0, unusedStars = 0, openedStars = 0, closedStars = 0, n = s.length();
        
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                diff++;
            } else if (s[i] == ')'){
                if(diff>0){
                    diff--;
                } else {
                    // diff is 0
                    if(unusedStars){
                        // '*' -> '('
                        unusedStars--;
                        openedStars++;
                    } else if(closedStars){
                        // ')' -> '*'
                        closedStars--;
                        unusedStars++;
                    } else {
                        return false;
                    }
                }
            } else {
                if(diff>0){
                    // '*' -> ')'   GREEDY
                    closedStars++;
                    diff--;
                } else {
                    // '*' -> '*'
                    unusedStars++;
                }
            }
        }
        
        return diff == 0;
    }
};