// https://www.interviewbit.com/problems/maximum-area-of-triangle/

// WRONG TEST CASES IN INTERVIEWBIT
// The way of calculating the distance varies with each test case

// Attempt 1 (Correct Code according to the question):

int Solution::solve(vector<string> &A) {
    int n = A.size();
    if(n == 0) return 0;
    int m = A[0].size();
    
    vector<vector<int>> colFirst(m, vector<int>(3, n));
    vector<vector<int>> colLast(m, vector<int>(3, -1));
    vector<vector<int>> rowFirst(n, vector<int>(3, m));
    vector<vector<int>> rowLast(n, vector<int>(3, -1));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(A[i][j] == 'r'){
                rowFirst[i][0] = min(rowFirst[i][0], j);
                rowLast[i][0] = max(rowLast[i][0], j);
            } 
            if(A[i][j] == 'g'){
                rowFirst[i][1] = min(rowFirst[i][1], j);
                rowLast[i][1] = max(rowLast[i][1], j);
            } 
            if(A[i][j] == 'b'){
                rowFirst[i][2] = min(rowFirst[i][2], j);
                rowLast[i][2] = max(rowLast[i][2], j);
            } 
        }
    }
    double res = 0;
    for(int j = 0; j<m; j++){
        for(int i = 0; i<n; i++){
            if(A[i][j] == 'r'){
                colFirst[j][0] = min(colFirst[j][0], i);
                colLast[j][0] = max(colLast[j][0], i);
            } 
            if(A[i][j] == 'g'){
                colFirst[j][1] = min(colFirst[j][1], i);
                colLast[j][1] = max(colLast[j][1], i);
            } 
            if(A[i][j] == 'b'){
                colFirst[j][2] = min(colFirst[j][2], i);
                colLast[j][2] = max(colLast[j][2], i);
            } 
        }
    }
    
    for(int j = 0; j<m; j++){
        for(int i = 0; i<n; i++){
            // cases for y axis line
            // {r, g}
            if(colFirst[j][0] < colLast[j][1]){
                res = max(res, ceil(abs((double)((colLast[j][1]-colFirst[j][0])*max(abs(rowFirst[i][2]-j), abs(rowLast[i][2]-j))))/2));
            }
            // {r, b}
            if(colFirst[j][0] < colLast[j][2]){
                res = max(res, ceil(abs((double)((colLast[j][2]-colFirst[j][0])*max(abs(rowFirst[i][1]-j), abs(rowLast[i][1]-j))))/2));
            }
            // {g, r}
            if(colFirst[j][1] < colLast[j][0]){
                res = max(res, ceil(abs((double)((colLast[j][0]-colFirst[j][1])*max(abs(rowFirst[i][2]-j), abs(rowLast[i][2]-j))))/2));
            }
            // {g, b}
            if(colFirst[j][1] < colLast[j][2]){
                res = max(res, ceil(abs((double)((colLast[j][2]-colFirst[j][1])*max(abs(rowFirst[i][0]-j), abs(rowLast[i][0]-j))))/2));
            }
            // {b, r}
            if(colFirst[j][2] < colLast[j][0]){
                res = max(res, ceil(abs((double)((colLast[j][0]-colFirst[j][2])*max(abs(rowFirst[i][1]-j), abs(rowLast[i][1]-j))))/2));
            }
            // {b, g}
            if(colFirst[j][2] < colLast[j][1]){
                res = max(res, ceil(abs((double)((colLast[j][1]-colFirst[j][2])*max(abs(rowFirst[i][0]-j), abs(rowLast[i][0]-j))))/2));
            }
        }
    }
    
    return res;
}

// Attempt 2 (Wrong Code according to the question but is partioally accepted):

int Solution::solve(vector<string> &A) {
    int n = A.size();
    if(n == 0) return 0;
    int m = A[0].size();
    
    vector<vector<int>> colFirst(m, vector<int>(3, n));
    vector<vector<int>> colLast(m, vector<int>(3, -1));
    vector<vector<int>> rowFirst(n, vector<int>(3, m));
    vector<vector<int>> rowLast(n, vector<int>(3, -1));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(A[i][j] == 'r'){
                rowFirst[i][0] = min(rowFirst[i][0], j);
                rowLast[i][0] = max(rowLast[i][0], j);
            } 
            if(A[i][j] == 'g'){
                rowFirst[i][1] = min(rowFirst[i][1], j);
                rowLast[i][1] = max(rowLast[i][1], j);
            } 
            if(A[i][j] == 'b'){
                rowFirst[i][2] = min(rowFirst[i][2], j);
                rowLast[i][2] = max(rowLast[i][2], j);
            } 
        }
    }
    double res = 0;
    for(int j = 0; j<m; j++){
        for(int i = 0; i<n; i++){
            if(A[i][j] == 'r'){
                colFirst[j][0] = min(colFirst[j][0], i);
                colLast[j][0] = max(colLast[j][0], i);
            } 
            if(A[i][j] == 'g'){
                colFirst[j][1] = min(colFirst[j][1], i);
                colLast[j][1] = max(colLast[j][1], i);
            } 
            if(A[i][j] == 'b'){
                colFirst[j][2] = min(colFirst[j][2], i);
                colLast[j][2] = max(colLast[j][2], i);
            } 
        }
    }
    
    for(int j = 0; j<m; j++){
        for(int i = 0; i<n; i++){
            // cases for y axis line
            // {r, g}
            if(colFirst[j][0] < colLast[j][1]){
                res = max(res, ceil(abs((double)((colLast[j][1]-colFirst[j][0]+1)*max(1+abs(rowFirst[i][2]-j), 1+abs(rowLast[i][2]-j))))/2));
            }
            // {r, b}
            if(colFirst[j][0] < colLast[j][2]){
                res = max(res, ceil(abs((double)((colLast[j][2]-colFirst[j][0]+1)*max(1+abs(rowFirst[i][1]-j), 1+abs(rowLast[i][1]-j))))/2));
            }
            // {g, r}
            if(colFirst[j][1] < colLast[j][0]){
                res = max(res, ceil(abs((double)((colLast[j][0]-colFirst[j][1]+1)*max(1+abs(rowFirst[i][2]-j), 1+abs(rowLast[i][2]-j))))/2));
            }
            // {g, b}
            if(colFirst[j][1] < colLast[j][2]){
                res = max(res, ceil(abs((double)((colLast[j][2]-colFirst[j][1]+1)*max(1+abs(rowFirst[i][0]-j), 1+abs(rowLast[i][0]-j))))/2));
            }
            // {b, r}
            if(colFirst[j][2] < colLast[j][0]){
                res = max(res, ceil(abs((double)((colLast[j][0]-colFirst[j][2]+1)*max(1+abs(rowFirst[i][1]-j), 1+abs(rowLast[i][1]-j))))/2));
            }
            // {b, g}
            if(colFirst[j][2] < colLast[j][1]){
                res = max(res, ceil(abs((double)((colLast[j][1]-colFirst[j][2]+1)*max(1+abs(rowFirst[i][0]-j), 1+abs(rowLast[i][0]-j))))/2));
            }
        }
    }
    
    return res;
}




