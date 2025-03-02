// https://leetcode.com/problems/sum-of-prefix-scores-of-strings/

// Method 1 (Trie, O(n*m)):

class Solution {
    struct TrieNode {
        int counter = 0;
        TrieNode * next[26];
    };
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();

        TrieNode * root = new TrieNode();
        for(string & word:words){
            TrieNode * cur = root;
            for(char c:word){
                if(cur->next[c-'a'] == nullptr){
                    cur->next[c-'a'] = new TrieNode(); 
                }
                cur = cur->next[c-'a'];
                cur->counter++;
            }
        }

        vector<int> scores(n);
        for(int i=0; i<n; i++){
            TrieNode * cur = root;
            for(char c:words[i]){
                cur = cur->next[c-'a'];
                scores[i] += cur->counter;
            }
        }

        return scores;
    }
};
