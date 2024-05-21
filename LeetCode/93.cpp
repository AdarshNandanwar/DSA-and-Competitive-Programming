// https://leetcode.com/problems/restore-ip-addresses/

// Method 1 (DFS, O(1)):

class Solution {
    bool isValidSequence(const string & sequenceString){
        if(sequenceString == ""){
            return false;
        }
        int sequenceInt = stoi(sequenceString);
        if(0 <= sequenceInt and
            sequenceInt <= 255 and
            (to_string(sequenceInt) == sequenceString)){
            return true;
        }
        return false;
    }
    void dfs(const string & s, int begin, int end, int sequenceIndex, string & cur, vector<string> & ans){
        int n = s.length();
        if(end == n){
            if(sequenceIndex == 3){
                string sequenceString = s.substr(begin, end-begin);
                if(isValidSequence(sequenceString)){
                    ans.push_back(cur + sequenceString);                    
                }
            }
            return;
        }
        if(sequenceIndex > 3 or end-begin > 3){
            return;
        }

        int sequenceLength = end-begin;
        string sequenceString = s.substr(begin, sequenceLength);
        if(isValidSequence(sequenceString)){
            cur += sequenceString;
            cur += ".";
            dfs(s, end, end+1, sequenceIndex+1, cur, ans);
            cur.pop_back();
            while(sequenceLength--){
                cur.pop_back();
            }
        }

        dfs(s, begin, end+1, sequenceIndex, cur, ans);
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string cur;
        dfs(s, 0, 0, 0, cur, ans);
        return ans;
    }
};
