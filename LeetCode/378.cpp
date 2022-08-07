// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

// Method 1 (Binary Search, O((n+m)*log2(2*1e9)) time, O(1) space):

class Solution {
    int countSmaller(vector<vector<int>>& matrix, int x){
        int n = matrix.size(), m = matrix[0].size();
        int i=0, j=m-1;
        int count = 0;
        while(i<n and j>=0){
            if(matrix[i][j] >= x){
                j--;
            } else {
                count += (j+1);
                i++;
            }
        }
        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // TF Last T
        int lo=-1e9, hi=1e9, mid;
        while(lo<hi){
            mid = lo+(hi-lo+1)/2;
            if(countSmaller(matrix, mid)<k){
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        return lo;
    }
};

// Method 2 (Priority Queue, O((m+k)*log2(m)) time, O(m) space):

// Clean Code (Reference Comparator Version):

class Solution {
    struct Cell{
        int val, row, col;
        Cell(int val, int row, int col): val(val), row(row), col(col){};
    };
    struct Comp{
        bool operator()(const Cell & a, const Cell & b) const {
            return a.val > b.val;
        }
    };
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        priority_queue<Cell, vector<Cell>, Comp> pq;
        
        for(int col=0; col<m; col++){
            Cell cell(matrix[0][col], 0, col);
            pq.push(cell);
        }
        
        k--;
        while(k--){
            Cell cell = pq.top();
            pq.pop();
            int row = cell.row;
            int col = cell.col;
            int nextRow = row+1;
            if(nextRow < n){
                Cell nextCell(matrix[nextRow][col], nextRow, col);
                pq.push(nextCell);
            }
        }
        return pq.top().val;
    }
};

// Clean Code (Pointer Comparator Version):

class Solution {
    struct Cell{
        int val, row, col;
        Cell(int val, int row, int col): val(val), row(row), col(col){};
    };
    struct Comp{
        bool operator()(const Cell * a, const Cell * b) const {
            return a->val > b->val;
        }
    };
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        priority_queue<Cell *, vector<Cell *>, Comp> pq;
        
        for(int col=0; col<m; col++){
            Cell * cell = new Cell(matrix[0][col], 0, col);
            pq.push(cell);
        }
        
        k--;
        while(k--){
            Cell * cell = pq.top();
            pq.pop();
            int row = cell->row;
            int col = cell->col;
            int nextRow = row+1;
            if(nextRow < n){
                Cell * nextCell = new Cell(matrix[nextRow][col], nextRow, col);
                pq.push(nextCell);
            }
        }
        return pq.top()->val;
    }
};

// Messy Code (Pair of Pair):

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        // {value, {i, j}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for(int j=0; j<m; j++){
            pq.push(make_pair(matrix[0][j], make_pair(0, j)));
        }
        k--;
        while(k--){
            auto cur = pq.top();
            pq.pop();
            int i = cur.second.first;
            int j = cur.second.second;
            int nextI = i+1;
            if(nextI < n){
                pq.push(make_pair(matrix[nextI][j], make_pair(nextI, j)));
            }
        }
        return pq.top().first;
    }
};