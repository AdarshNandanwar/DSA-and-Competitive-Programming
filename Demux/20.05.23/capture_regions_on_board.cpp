// https://www.interviewbit.com/problems/capture-regions-on-board/

bool isValid(vector<vector<char> > &A, int n, int m, int i, int j, vector<vector<bool>> & visited){
    
    if(i<0 or i>=n or j<0 or j>=m) return false;
    
    if(A[i][j] == 'X' or visited[i][j]) return true;
    
    visited[i][j] = true;
    
    int X[4] = {1, 0, -1, 0}, Y[4] = {0, 1, 0, -1};
    bool res = true;
    
    for(int k = 0; k<4; k++){
        if(!isValid(A, n, m, i+Y[k], j+X[k], visited)) res = false;
    }
    return res;
}

void flipRegion(vector<vector<char> > &A, int n, int m, int i, int j, vector<vector<bool>> & visited){
    
    if(i<0 or i>=n or j<0 or j>=m or A[i][j] == 'X' or visited[i][j]) return;
    
    visited[i][j] = true;
    A[i][j] = 'X';
    
    int X[4] = {1, 0, -1, 0}, Y[4] = {0, 1, 0, -1};
    
    for(int k = 0; k<4; k++){
        flipRegion(A, n, m, i+Y[k], j+X[k], visited);
    }
}

void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    if(n == 0) return;
    int m = A[0].size();
    vector<vector<bool>> visitedValid(n, vector<bool>(m, false)), visitedFlip(n, vector<bool>(m, false));
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!visitedValid[i][j] and A[i][j] == 'O' and isValid(A, n, m, i, j, visitedValid))
                flipRegion(A, n, m, i, j, visitedFlip);
        }
    }
}
