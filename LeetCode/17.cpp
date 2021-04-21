// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

// Method 1 (Recursion):

class Solution {
public:
    
    void helper(int index, string & digits, vector<string> & keys, string & cur, vector<string> & ans){
        if(index == digits.length()){
            ans.push_back(cur);
            return;
        }
        for(auto & i:keys[digits[index]-'0']){
            cur.push_back(i);
            helper(index+1, digits, keys, cur, ans);
            cur.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        vector<string> ans, keys = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string cur = "";
        helper(0, digits, keys, cur, ans);
        return ans;
    }
};

// Method 2 (Recursion with linked list):

unordered_map<char, vector<char>> m = {
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y', 'z'}}
};

class Solution {
public:
    
    void solve(string & digits, int index, list<string> & ll){
        if(index >= digits.length()) return;
        for(auto itr = ll.begin(); itr!=ll.end();){
            for(auto i:m[digits[index]]){
                ll.push_front(*itr+char(i));
            }
            auto temp = itr;
            itr++;
            ll.erase(temp);
        }
        solve(digits, index+1, ll);
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return vector<string>(0);
        list<string> ll(1, "");
        solve(digits, 0, ll);
        vector<string> ans;
        for(auto i:ll) ans.push_back(i);
        return ans;
    }
};