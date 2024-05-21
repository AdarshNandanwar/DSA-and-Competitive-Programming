// https://leetcode.com/problems/word-search/

// Method 1 (DFS + Optimization, O( n*m*4^(word.length()) )):

class Solution {
    vector<int> dir = {0, -1, 0, 1, 0};
    bool dfs(const vector<vector<char>>& board, int row, int col, const string& word, int index, vector<vector<bool>>& visited){
        int n = board.size();
        int m = board[0].size();
        if(index >= word.length()){
            return true;
        }
        if(row<0 or col<0 or row>=n or col>=m or visited[row][col] or board[row][col] != word[index]){
            return false;
        }
        visited[row][col] = true;
        int result = false;
        for(int i=0; i<4; i++){
            int nextRow = row + dir[i];
            int nextCol = col + dir[i+1];
            if(dfs(board, nextRow, nextCol, word, index+1, visited)){
                result = true;
                break;
            }
        }
        visited[row][col] = false;
        return result;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        // Pruning: Check if board has required characters
        unordered_map<char, int> required;
        for(char c:word){
            required[c]++;
        }
        unordered_map<char, int> available;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                available[board[i][j]]++;
            }
        }
        for(pair<char, int> cur:required){
            if(cur.second > available[cur.first]){
                return false;
            }
        }

        // Optimization: Reduce starting points.
        if(available[word.front()] > available[word.back()]){
            reverse(word.begin(), word.end());
        }

        // DFS
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dfs(board, i, j, word, 0, visited)){
                    return true;
                }
            }
        }
        return false;
    }
};

// Method 2 (DFS, O( n*m*4^(word.length()) )):

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