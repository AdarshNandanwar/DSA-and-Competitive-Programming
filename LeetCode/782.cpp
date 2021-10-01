// https://leetcode.com/problems/transform-to-chessboard/

// https://leetcode.com/problems/transform-to-chessboard/

// Method 1 (Only 2 unique with one complement of the other, O(n2)):

class Solution {
public:
    
    int get_cost(vector<int> & row, vector<int> & col){
        int n = row.size();
        
        int row_sum = 0, col_sum = 0;
        for(auto &i:row) if(i) row_sum++;
        for(auto &i:col) if(i) col_sum++;
        
        if(row_sum != col_sum) return INT_MAX;
        if(row_sum != n/2 and n-row_sum != n/2) return INT_MAX;
        
        int zero_start_cost = 0, one_start_cost = 0;
        for(int i = 0; i<n; i+=2){
            if(row[i] != 0) zero_start_cost++;
            else one_start_cost++;
            
            if(col[i] != 0) zero_start_cost++;
            else one_start_cost++;
        }
        
        if(n%2 == 0){
            return min(zero_start_cost, one_start_cost);
        } else {
            if(row_sum == n/2+1){
                // 1 is in majority
                return one_start_cost;
            } else {
                // 0 is in majority
                return zero_start_cost;
            }
        }
    }
    
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        
        // ensure there are only 2 unique rows, one complement of the other
        for(int i = 0; i<n; i++){
            bool flag = 0;
            for(int j = 0; j<n; j++){
                if(board[i][j] != board[0][j]) flag = 1;
            }
            if(flag == 0) continue;
            flag = 0;
            for(int j = 0; j<n; j++){
                if(board[i][j] != !board[0][j]) flag = 1;
            }
            if(flag == 1) return -1;
        }
        
        // ensure there are only 2 unique cols, one complement of the other
        for(int j = 0; j<n; j++){
            bool flag = 0;
            for(int i = 0; i<n; i++){
                if(board[i][j] != board[i][0]) flag = 1;
            }
            if(flag == 0) continue;
            flag = 0;
            for(int i = 0; i<n; i++){
                if(board[i][j] != !board[i][0]) flag = 1;
            }
            if(flag == 1) return -1;
        }
        
        vector<vector<int>> rows(2, vector<int>(n, 0)), cols(2, vector<int>(n, 0));
        for(int i = 0; i<n; i++){
            rows[0][i] = board[0][i];
            rows[1][i] = !board[0][i];
            cols[0][i] = board[i][0];
            cols[1][i] = !board[i][0];
        }
        
        // trying all possible combinations to select the first row and first column
        int res = INT_MAX;
        res = min(res, get_cost(rows[0], cols[0]));
        res = min(res, get_cost(rows[0], cols[1]));
        res = min(res, get_cost(rows[1], cols[0]));
        res = min(res, get_cost(rows[1], cols[1]));
        
        return res==INT_MAX ? -1 : res;
    }
};

// Method 2 (Same logic but coded differently, O(n2)):

class Solution {
public:
    
    int get_cost(vector<int> & row, vector<int> & col){
        int n = row.size();
        
        int row_sum = 0, col_sum = 0;
        for(auto &i:row) if(i) row_sum++;
        for(auto &i:col) if(i) col_sum++;
        
        if(row_sum != col_sum) return INT_MAX;
        if(row_sum != n/2 and n-row_sum != n/2) return INT_MAX;
        
        int zero_start_cost = 0, one_start_cost = 0;
        for(int i = 0; i<n; i+=2){
            if(row[i] != 0) zero_start_cost++;
            else one_start_cost++;
            
            if(col[i] != 0) zero_start_cost++;
            else one_start_cost++;
        }
        
        if(n%2 == 0){
            return min(zero_start_cost, one_start_cost);
        } else {
            if(row_sum == n/2+1){
                // 1 is in majority
                return one_start_cost;
            } else {
                // 0 is in majority
                return zero_start_cost;
            }
        }
    }
    
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        
        // ensure there are only 2 unique rows, one starting with 0 and other with 1
        vector<bool> done;
        vector<vector<int>> rows(2, vector<int>(n, 0));
        done = vector<bool>(2, false);
        for(int i = 0; i<n; i++){
            if(!done[board[i][0]]){
                for(int j = 0; j<n; j++){
                    rows[board[i][0]][j] = board[i][j];
                }
                done[board[i][0]] = true;
            } else {
                for(int j = 0; j<n; j++){
                    if(board[i][j] != rows[board[i][0]][j]) return -1;
                }
            }
        }
        // validating the 2 options
        if(!done[0] or !done[1]) return -1;
        for(int j = 0; j<n; j++){
            if(rows[0][j]+rows[1][j] != 1) return -1;
        }
        
        // ensure there are only 2 unique cols, one starting with 0 and other with 1
        vector<vector<int>> cols(2, vector<int>(n, 0));
        done = vector<bool>(2, false);
        for(int j = 0; j<n; j++){
            if(!done[board[0][j]]){
                for(int i = 0; i<n; i++){
                    cols[board[0][j]][i] = board[i][j];
                }
                done[board[0][j]] = true;
            } else {
                for(int i = 0; i<n; i++){
                    if(board[i][j] != cols[board[0][j]][i]) return -1;
                }
            }
        }
        // validating the 2 options
        if(!done[0] or !done[1]) return -1;
        for(int i = 0; i<n; i++){
            if(cols[0][i]+cols[1][i] != 1) return -1;
        }
        
        // trying all possible combinations to select the first row and first column
        int res = INT_MAX;
        res = min(res, get_cost(rows[0], cols[0]));
        res = min(res, get_cost(rows[0], cols[1]));
        res = min(res, get_cost(rows[1], cols[0]));
        res = min(res, get_cost(rows[1], cols[1]));
        
        return res==INT_MAX ? -1 : res;
    }
};