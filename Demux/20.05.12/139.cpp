// https://leetcode.com/problems/word-break/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> st;
        for(string word:wordDict){
            st.insert(word);
        }
        vector<bool> dp(n+1, false);
        // dp[i] = is substring [i,n) breakable ?
        dp[n] = true;
        for(int i=n-1; i>=0; i--){
            string curr = "";
            for(int j=i; j<n; j++){
                curr += s[j];
                // curr = s[i,j] inclusive
                if(st.find(curr) != st.end() and dp[j+1]){
                    dp[i] = true;
                }
            }
        }
        return dp[0];
    }
};

// NOT WORKING (TRIE ATTEMPT)

class TrieNode {
    public:
    bool is_word;
    TrieNode * next[26];
    TrieNode(){
        is_word = false;
        for(int i=0; i<26; i++){
            next[i] = NULL;
        }
    }
};

class Solution {
public:
    
    bool helper(string & s, TrieNode * root, int index, TrieNode * mainRoot, vector<int> & dp){
        
        if(root == NULL)
            return false;
        
        if(index == s.length())
            if(root->is_word)
                return true;
            else
                return false;
        
        if(dp[index] != -1)
            return dp[index];
        
        bool res = (root->is_word and helper(s, mainRoot->next[s[index]-'a'], index+1, mainRoot, dp)) 
            or helper(s, root->next[s[index]-'a'], index+1, mainRoot, dp);
        
        dp[index] = res;
        return res;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        TrieNode * root = new TrieNode();
        TrieNode * curr = root;
        vector<int> dp(n+1, -1);
        
        // insert in trie
        for(string word:wordDict){
            curr = root;
            for(int i=0; i<word.length(); i++){
                if(curr->next[word[i]-'a'] == NULL)
                    curr->next[word[i]-'a'] = new TrieNode();
                curr = curr->next[word[i]-'a'];
            }
            curr->is_word = true;
        }
        
        return helper(s, root, 0, root, dp);
    }
};