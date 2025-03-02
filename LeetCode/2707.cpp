// https://leetcode.com/problems/extra-characters-in-a-string/

// Method 1 (Trie, Recursion, DP, O(len(s) * #roots * len(longest_word)) = O(n * m*m * m) = O(n * m3) = O(n4)):

class Solution {
    struct Trie{
        bool isWord;
        Trie * next[26];
    };

    int helper(const string & s, int index, Trie * root, vector<unordered_map<Trie *, int>> & dp){
        int n = s.length();
        if(index == n){
            return 0;
        }

        if(dp[index].count(root)){
            return dp[index][root];
        }

        // Consider s[index] is extra
        int res = 1 + helper(s, index+1, root, dp);

        Trie * cur = root;
        for(int i=index; i<n; i++){
            if(cur->next[s[i]-'a'] == nullptr){
                break;
            }
            cur = cur->next[s[i]-'a'];
            if(cur->isWord){
                res = min(res, helper(s, i+1, root, dp));
            }
        }

        return dp[index][root] = res;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();

        Trie * root = new Trie();
        
        for(string & word:dictionary){
            Trie * cur = root;
            for(char c:word){
                if(cur->next[c-'a'] == nullptr){
                    cur->next[c-'a'] = new Trie();
                }
                cur = cur->next[c-'a'];
            }
            cur->isWord = true;
        }

        vector<unordered_map<Trie *, int>> dp(n);

        return helper(s, 0, root, dp);
    }
};
