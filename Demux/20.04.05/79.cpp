// https://leetcode.com/problems/word-search/

class Solution {
public:
    
    bool helper(vector<vector<char>> & board, int x, int y, int index, string & word, vector<vector<bool>> & visited, int n, int m){
        
        if(index == word.length()){
            return true;
        }
        
        if(x<0 || n<=x || y<0 || m<=y) return false;
        
        if(visited[x][y]) return false;
        
        if(board[x][y] != word[index]) return false;
        
        visited[x][y] = true;
        
        bool ans = false;
        int X[4] = {0, 1, 0, -1};
        int Y[4] = {1, 0, -1, 0};
        for(int i = 0; i<4; i++){
            if(helper(board, x+X[i], y+Y[i], index+1, word, visited, n, m)){
                ans = true;
                break;
            }
        }
        visited[x][y] = false;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size(), l = word.length();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(helper(board, i, j, 0, word, visited, n, m)) return true;
            }
        }
        return false;
    }
};