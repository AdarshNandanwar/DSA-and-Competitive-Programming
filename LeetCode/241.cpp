// https://leetcode.com/problems/different-ways-to-add-parentheses/

// Method 1 (Recursion + DP):

class Solution {
public:
    unordered_map<string, vector<int>> dp;
    
    vector<int> diffWaysToCompute(string expression) {
        if(dp.count(expression)){
            return dp[expression];
        }
        int n = expression.length();
        vector<int> options;
        for(int i=0; i<n; i++){
            if(!isdigit(expression[i])){
                string left = expression.substr(0, i);
                string right = expression.substr(i+1);
                auto leftOptions = diffWaysToCompute(left);
                auto rightOptions = diffWaysToCompute(right);
                for(auto &leftValue:leftOptions){
                    for(auto &rightValue:rightOptions){
                        int value = 0;
                        if(expression[i] == '+'){
                            value = leftValue+rightValue;
                        } else if(expression[i] == '-'){
                            value = leftValue-rightValue;
                        } else if(expression[i] == '*'){
                            value = leftValue*rightValue;
                        }
                        options.push_back(value);
                    }
                }
            }
        }
        if(options.size() == 0){
            options.push_back(stoi(expression));
        }
        return dp[expression] = options;
    }
};