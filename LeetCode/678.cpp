// https://leetcode.com/problems/valid-parenthesis-string/

// Method 1 (Greedy, O(n)):

class Solution {
public:
    bool checkValidString(string s) {
        int open = 0, starClose = 0, starOpen = 0;
        for(char c:s){
            if(c == '('){
                open++;
            } else if(c == ')'){
                if(open > 0){
                    open--;
                } else if(starOpen > 0){
                    starOpen--;
                } else if(starClose > 0){
                    starClose--;
                    starOpen++;
                } else {
                    return false;
                }
            } else {
                if(open > 0){
                    open--;
                    starClose++;
                } else {
                    starOpen++;
                }
            }
        }
        return open == 0;
    }
};

// Alternate Code:

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
