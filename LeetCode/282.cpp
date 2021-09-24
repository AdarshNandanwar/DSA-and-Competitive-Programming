// https://leetcode.com/problems/expression-add-operators/

// Method 1 (Backtracking):

class Solution {
public:
    
    void helper(const string & num, int st, const int & target, long cumulative_value, long prev_value, int prev_sign, string cur, vector<string> &ans){
        int n = num.length();
        if(st == n){
            if(cumulative_value == target) ans.push_back(cur);
            return;
        }
        long prefix_value = 0;
        string prefix = "";
        for(int i = st; i<n; i++){
            if(prefix == "0") break;
            prefix_value = prefix_value*10+(num[i]-'0');
            prefix.push_back(num[i]);
            if(st == 0){
                helper(num, i+1, target, prefix_value, prefix_value, +1, prefix, ans);
            } else {
                // Multiplication
                long next_multi_value = cumulative_value + (prev_sign)*(-prev_value+prev_value*prefix_value);
                helper(num, i+1, target, next_multi_value, prev_value*prefix_value, prev_sign, cur+"*"+prefix, ans);
                // Addition
                helper(num, i+1, target, cumulative_value+prefix_value, prefix_value, +1, cur+"+"+prefix, ans);
                // Subtraction
                helper(num, i+1, target, cumulative_value-prefix_value, prefix_value, -1, cur+"-"+prefix, ans);
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        helper(num, 0, target, 0, 0, +1, "", ans);
        return ans;
    }
};