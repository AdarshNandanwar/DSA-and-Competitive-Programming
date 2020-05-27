// https://leetcode.com/problems/word-break-ii/

// Method 1 (DP):

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> st;
        
        for(auto word:wordDict){
            st.insert(word);
        }
        
        // is partitionable? dp
        vector<bool> partitionable(n+1, false);
        
        // partitionable[i] = is substring [i,n) breakable ?
        partitionable[n] = true;
        for(int i=n-1; i>=0; i--){
            string curr = "";
            for(int j=i; j<n; j++){
                curr += s[j];
                // curr = s[i,j] inclusive
                if(st.find(curr) != st.end() and partitionable[j+1]){
                    partitionable[i] = true;
                }
            }
        }
        
        
        if(!partitionable[0])
            return vector<string>();
        
        // ans dp
        vector<unordered_set<string>> dp(n+1);
        
        for(int i=n-1; i>=0; i--){
            string curr = "";
            for(int j=i; j<n; j++){
                curr += s[j];
                if(partitionable[j+1] and st.find(curr) != st.end()){
                    if(j+1==n){
                        dp[i].insert(curr);
                    } else {
                        for(auto str:dp[j+1]){
                            dp[i].insert(curr+" "+str);
                        }
                    }
                }
            }
        }
        
        vector<string> ans(dp[0].begin(), dp[0].end());
        return ans;
    }
};

// Method 2 (Recursion):

class Solution {
public:
    
    
    void getStrings(string & s, string tillNow, vector<string> & ans, int start, unordered_set<string> & st, vector<bool> & partitionable){
        int n = s.length();
        
        if(start == n){
            tillNow = tillNow.substr(0, tillNow.length()-1);
            ans.push_back(tillNow);
            return;
        }
        
        string curr = "";
        for(int i = start; i<n; i++){
            curr += s[i];
            // checking partitionable stops backtracking and saves time
            if(partitionable[i+1] and st.find(curr) != st.end()){
                getStrings(s, tillNow+curr+" ", ans, i+1, st, partitionable);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> st;
        
        for(auto word:wordDict){
            st.insert(word);
        }
        
        
        // calculating partitionable to prevent backtracking and save time
        
        // is partitionable? dp
        vector<bool> partitionable(n+1, false);
        // partitionable[i] = is substring [i,n) breakable ?
        partitionable[n] = true;
        for(int i=n-1; i>=0; i--){
            string curr = "";
            for(int j=i; j<n; j++){
                curr += s[j];
                // curr = s[i,j] inclusive
                if(st.find(curr) != st.end() and partitionable[j+1]){
                    partitionable[i] = true;
                }
            }
        }
        


        vector<string> ans;        
        string curr = "";
        
        getStrings(s, curr, ans, 0, st, partitionable);
               
        return ans;
    }
};