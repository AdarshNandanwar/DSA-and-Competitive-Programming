// https://www.interviewbit.com/problems/word-search-board/

int dir[5] = {0, 1, 0, -1, 0};

bool helper(vector<string> &A, const string & B, int index, int i, int j){
    int n = A.size(), m = A[0].size();
    if(index == B.size()) return 1;
    if(i<0 or j<0 or i>=n or j>=m or A[i][j] != B[index]) return 0;
    for(int x = 0; x<4; x++) if(helper(A, B, index+1, i+dir[x], j+dir[x+1])) return 1;
    return 0;
}

int Solution::exist(vector<string> &A, string B) {
    int n = A.size();
    if(n == 0) return 0;
    int m = A[0].length();
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(helper(A, B, 0, i, j)) return 1;
        }
    }
    return 0;
}