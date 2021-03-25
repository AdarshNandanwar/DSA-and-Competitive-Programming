// https://leetcode.com/problems/concatenated-words/

struct TrieNode{
    bool is_word;
    TrieNode * next[26];
    TrieNode(){
        is_word = false;
        for(int i = 0; i<26; i++){
            next[i] = NULL;
        }
    }
};

class Solution {
public:
    
    bool findHelper(TrieNode * root, TrieNode * curr, string & word, int index, int count){
        
        if(curr == NULL)
            return false;
        
        if(index == word.length())
            if(count>1 and curr->is_word){
                return true;
            }
            else
                return false;
        
        if(curr->is_word)
            if(findHelper(root, root->next[word[index]-'a'], word, index+1, count+1)){
                return true;
            }
        
        return findHelper(root, curr->next[word[index]-'a'], word, index+1, count);
    }
    
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        TrieNode * root = new TrieNode();
        TrieNode * curr = root;
        int  n = words.size(), m;
        
        // Insertion
        
        for(int i = 0; i< n; i++){
            curr = root;
            m = words[i].size();
            for(int j = 0; j<m; j++){
                if(curr->next[words[i][j]-'a'] == NULL)
                    curr->next[words[i][j]-'a'] = new TrieNode();
                curr = curr->next[words[i][j]-'a'];
            }
            if(m)
                curr->is_word = true;
        }
        
        // Searching
        
        vector<string> ans;
        
        for(int i = 0; i< n; i++){
            if(findHelper(root, root, words[i], 0, 1)){
                ans.push_back(words[i]);
            }
        }
        return ans;
        
    }
};