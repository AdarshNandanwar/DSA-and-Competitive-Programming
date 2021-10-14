// https://leetcode.com/problems/word-search/

// Method 1 (DFS, O( n*m*4^(word.length()) )):

class Solution {
public:
    
    vector<int> dir = {0, -1, 0, 1, 0};
    
    bool helper(vector<vector<char>> & board, const string & word, const int i, const int j, const int index){
        int n = board.size(), m = board[0].size();
        if(index == word.length()) return true;
        if(i<0 or i>=n or j<0 or j>=m or board[i][j] != word[index]) return false;
        char letter = board[i][j];
        board[i][j] = 0;    // visited
        for(int k = 0; k<4; k++){
            int iNbr = i+dir[k], jNbr = j+dir[k+1];
            if(helper(board, word, iNbr, jNbr, index+1)) return true;
        }
        board[i][j] = letter;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(helper(board, word, i, j, 0))
                    return true;                
            }
        }
        return false;
    }
};