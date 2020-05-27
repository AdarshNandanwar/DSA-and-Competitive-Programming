// https://leetcode.com/problems/word-search-ii/

struct TrieNode{
    bool is_word;
    string str;
    TrieNode * next[26];
    TrieNode(){
        str = "";
        is_word = false;
        for(int i =0; i<26; i++){
            next[i] = NULL;
        }
    }
};

class Solution {
public:
    
    bool isValid(vector<vector<char>>& board, int i, int j){
        bool res = i<0 || j<0 || i>= board.size() || j>= board[0].size();
        return (!res);
    }
    
    void findWord(vector<vector<char>>& board, TrieNode * curr, vector<vector<bool>> & visited, int i, int j, unordered_set<string> & ans_set) {
        
        if(curr == NULL) 
            return;
        
        if(curr->is_word)
            ans_set.insert(curr->str);
        
        visited[i][j] = true;
        
        vector<int> x = {0, 1, 0, -1};
        vector<int> y = {1, 0, -1, 0};
        for(int k = 0; k<4; k++){
            if(isValid(board, i+x[k], j+y[k]) and !visited[i+x[k]][j+y[k]])
                findWord(board, curr->next[board[i+x[k]][j+y[k]]-'a'], visited, i+x[k], j+y[k], ans_set);
        }
              
        visited[i][j] = false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        int n = board.size();
        if(n == 0){
            return ans;
        }
        
        unordered_set<string> ans_set;
        int m;    
        
        TrieNode dummy;
        TrieNode * root = &dummy, * curr;
        
        // insert
        for(string word:words){
            curr = root;
            m = word.length();
            for(int j = 0; j<m; j++){
                if(curr->next[word[j]-'a'] == NULL)
                    curr->next[word[j]-'a'] = new TrieNode();
                curr = curr->next[word[j]-'a'];
            }
            curr->is_word = true;
            curr->str = word;
        }
        
        
        // search
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        m = board[0].size();
        
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m ; j++)
                findWord(board, root->next[board[i][j]-'a'], visited, i, j, ans_set);
        
        
        for(auto i:ans_set){
            ans.push_back(i);
        }
        
        return ans;
    }
};