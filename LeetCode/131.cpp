// https://leetcode.com/problems/palindrome-partitioning/

// Method 1 (Recursion, O(n)):

class Solution {
public:
    bool isPalindrome(const string & s, int st, int end){
        while(st<end){
            if(s[st] != s[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
    
    void generatePartitions(const string & s, int start, vector<vector<string>> & ans, vector<string> & cur){
        int n = s.length();
        if(start == n){
            ans.push_back(cur);
            return;
        }
        for(int i=start; i<n; i++){
            if(isPalindrome(s, start, i)){
                cur.push_back(s.substr(start, i-start+1));
                generatePartitions(s, i+1, ans, cur);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        generatePartitions(s, 0, ans, cur);
        return ans;
    }
};