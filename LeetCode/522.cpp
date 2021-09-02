// https://leetcode.com/problems/longest-uncommon-subsequence-ii/

// Method 1 (Brute Force, O(50*2^10)):

class Solution {
public:
    bool is_subsequence(string & s1, string & s2){
        int j = 0;
        for(int i = 0; i<s1.length(); i++){
            if(s1[i] == s2[j]) j++;
            if(j == s2.length()) return true;
        }
        return false;
    }
    
    void helper(vector<string>& strs, int i, int j, string & cur, int & ans){
        if(j == strs[i].length()){
            int len = cur.length();
            if(len <= ans) return;
            bool flag = 1;
            for(int k = 0; k<strs.size(); k++){
                if(k == i) continue;
                if(is_subsequence(strs[k], cur)){
                    flag = 0;
                    break;
                } 
            }
            if(flag) ans = max(ans, len);
            return;
        }
        helper(strs, i, j+1, cur, ans);
        cur.push_back(strs[i][j]);
        helper(strs, i, j+1, cur, ans);
        cur.pop_back();
    }
    
    int findLUSlength(vector<string>& strs) {
        int ans = 0;
        for(int i = 0; i<strs.size(); i++){
            string cur = "";
            helper(strs, i, 0, cur, ans);
        }
        return ans == 0? -1 : ans;
    }
};