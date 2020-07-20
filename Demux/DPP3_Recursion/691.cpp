// https://leetcode.com/problems/stickers-to-spell-word/

class Solution {
public:
    
    int solve(vector<int> & targetFreq, vector<vector<int>> & freq, map<string, int> & dp){
        
        string target = "";
        for(auto i = 0; i<26; i++) target += string(targetFreq[i], 'a'+i);
        
        if(target.length() == 0) return 0;
        
        if(dp.count(target)) return dp[target];
        
        int res = 100;
        
        for(auto i = 0; i<freq.size(); i++){
            if(freq[i][target[0]-'a'] == 0) continue;
            vector<int> temp = targetFreq;
            for(auto j = 0; j<26; j++){
                temp[j] = max(0, temp[j]-freq[i][j]);
            }
            res = min(res, 1+solve(temp, freq, dp));
        }
        
        return dp[target] = res;
    }
    
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        vector<vector<int>> freq(n, vector<int>(26, 0));
        vector<int> targetFreq(26, 0);
        map<string, int> dp;
        for(int i = 0; i<n; i++){
            for(auto c:stickers[i]){
                freq[i][c-'a']++;
            }
        }
        for(auto c:target) targetFreq[c-'a']++;
        
        int minCount = solve(targetFreq, freq, dp);
        
        return minCount>=100?-1:minCount;
    }
};