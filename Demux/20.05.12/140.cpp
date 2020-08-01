// https://leetcode.com/problems/word-break-ii/

// Method 1 (Trie, DP):

struct TrieNode{
    bool isWord;
    string val;
    TrieNode * next[128];
    TrieNode(){
        isWord = false;
        val = "";
        for(int i = 0; i<128; i++){
            next[i] = NULL;
        }
    }
};

void helper(string & s, int index, TrieNode & dummy, TrieNode * cur, string & curStr, vector<string> & ans){
    if(cur == NULL) return;
    if(index == s.length()){
        if(cur->isWord){
            string entry;
            if(curStr.length()) entry = curStr + " " + cur->val;
            else entry = cur->val;
            ans.push_back(entry);
        }
        return;
    }
    
    if(cur->isWord){
        string temp;
        if(curStr.length()) temp = curStr + " " + cur->val;
        else temp = cur->val;
        helper(s, index+1, dummy, dummy.next[s[index]], temp, ans);
    }
    
    if(cur->next[s[index]]){
        helper(s, index+1, dummy, cur->next[s[index]], curStr, ans);
    }
}

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        // checking if the string can be partitioned
        int ns = s.length();
        unordered_set<string> us;
        for(auto w:wordDict) us.insert(w);
        // partitionable[i] = if [i, n) is partitionable ?
        vector<bool> partitionable(ns+1, 0);
        partitionable[ns] = 1;
        for(int i = ns-1; i>=0; i--){
            string cur = "";
            for(int j = i; j<ns; j++){
                cur.push_back(s[j]);
                if(us.count(cur) and partitionable[j+1]){
                    partitionable[i] = 1;
                    break;
                }
            }
        }
        
        if(partitionable[0] == 0) return vector<string>();
        
        TrieNode dummy;
        TrieNode * cur = &dummy;
        
        // insert into trie
        for(auto w:wordDict){
            if(w.length() == 0) continue;
            cur = &dummy;
            for(auto c:w){
                if(cur->next[c] == NULL) cur->next[c] = new TrieNode();
                cur = cur->next[c];                
            }
            cur->val = w;
            cur->isWord = 1;
        }
        
        vector<string> ans;
        string curStr = "";
        helper(s, 0, dummy, &dummy, curStr, ans);
        return ans;
    }
};

// Method 2 (DP):

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

// Method 3 (Recursion):

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