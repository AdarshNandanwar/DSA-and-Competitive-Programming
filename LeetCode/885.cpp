// https://leetcode.com/problems/spiral-matrix-iii/

// Method 1 (Loops, O(n*m) time, O(1) space):

class Solution {
    bool isValid(int n, int m, int i, int j){
        return i>=0 and j>=0 and i<n and j<m;
    }
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> path;
        path.push_back({rStart, cStart});
        
        int dist = 1;
        while(path.size() < rows * cols){
            cout<<path.size()<<endl;
            for(int i=rStart-dist+1; i<rStart+dist; i++){
                int j = cStart+dist;
                if(isValid(rows, cols, i, j)){
                    path.push_back({i, j});
                }
            }
            for(int j=cStart+dist; j>cStart-dist; j--){
                int i = rStart+dist;
                if(isValid(rows, cols, i, j)){
                    path.push_back({i, j});
                }
            }
            for(int i=rStart+dist; i>rStart-dist; i--){
                int j = cStart-dist;
                if(isValid(rows, cols, i, j)){
                    path.push_back({i, j});
                }
            }
            for(int j=cStart-dist; j<=cStart+dist; j++){
                int i = rStart-dist;
                if(isValid(rows, cols, i, j)){
                    path.push_back({i, j});
                }
            }

            dist++;
        }

        return path;
    }
};
