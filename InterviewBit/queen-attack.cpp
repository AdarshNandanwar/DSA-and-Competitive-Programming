// https://www.interviewbit.com/problems/queen-attack/

// Method 1 (DP, most generalized, O(n*m)):

#include<bits/stdc++.h>
// must be in the same order as in dp
// {l, tl, t, tr, r, br, b, bl}
int X[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int Y[8] = {0, -1, -1, -1, 0, 1, 1, 1};
vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    int n = A.size(), m = A[0].length(), I, J;
    vector<vector<int>> ans(n, vector<int>(m, 0));
    
    // danger[i][j][k] = is danger at A[i][j] from dir k = {l, tl, t, tr, r, br, b, bl}
    vector<vector<vector<bool>>> danger(n, vector<vector<bool>>(m, vector<bool>(8, 0)));
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            for(int k = 0; k<4; k++){
                I = i+Y[k]; J = j+X[k];
                if(I>=0 and I<n and J>=0 and J<m and (danger[I][J][k] or A[I][J] == '1')) danger[i][j][k] = 1;
            }
        }
    }
    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            for(int k = 4; k<8; k++){
                I = i+Y[k]; J = j+X[k];
                if(I>=0 and I<n and J>=0 and J<m and (danger[I][J][k] or A[I][J] == '1')) danger[i][j][k] = 1;
            }
        }
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            ans[i][j] = accumulate(danger[i][j].begin(), danger[i][j].end(), 0);
        }
    }
    return ans;
}

// Method 2 (DP, O(n*m)):

#include<bits/stdc++.h>

vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    int n = A.size();
    if(n == 0) return {};
    int m = A[0].length();
    vector<vector<int>> ans(n, vector<int>(m, 0));
    
    // danger[i][j][k] = is danger at A[i][j] from dir k {l, tl, t, tr, r, br, b, bl}
    vector<vector<vector<bool>>> danger(n, vector<vector<bool>>(m, vector<bool>(8, 0)));
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(j-1>=0 and (danger[i][j-1][0] or A[i][j-1] == '1')) danger[i][j][0] = 1;
            if(i-1>=0 and j-1>=0 and (danger[i-1][j-1][1] or A[i-1][j-1] == '1')) danger[i][j][1] = 1;
            if(i-1>=0 and (danger[i-1][j][2] or A[i-1][j] == '1')) danger[i][j][2] = 1;
            if(i-1>=0 and j+1<m and (danger[i-1][j+1][3] or A[i-1][j+1] == '1')) danger[i][j][3] = 1;
        }
    }
    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            if(j+1<m and (danger[i][j+1][4] or A[i][j+1] == '1')) danger[i][j][4] = 1;
            if(i+1<n and j+1<m and (danger[i+1][j+1][5] or A[i+1][j+1] == '1')) danger[i][j][5] = 1;
            if(i+1<n and (danger[i+1][j][6] or A[i+1][j] == '1')) danger[i][j][6] = 1;
            if(i+1<n and j-1>=0 and (danger[i+1][j-1][7] or A[i+1][j-1] == '1')) danger[i][j][7] = 1;
        }
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            ans[i][j] = accumulate(danger[i][j].begin(), danger[i][j].end(), 0);
        }
    }
    return ans;
}

// Method 3 (DP, uses extra space, O(n*m)):

vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    int n = A.size();
    if(n == 0) return {};
    int m = A[0].length();
    vector<vector<int>> ans(n, vector<int>(m, 0));
    vector<bool> u(m, 0);
    vector<bool> d(m, 0);
    vector<bool> l(n, 0);
    vector<bool> r(n, 0);
    vector<bool> tl(n+m-1, 0);
    vector<bool> bl(n+m-1, 0);
    vector<bool> br(n+m-1, 0);
    vector<bool> tr(n+m-1, 0);
    
    // isSafe
    vector<vector<int>> topHalf(n, vector<int>(m, 0));
    vector<vector<int>> bottomHalf(n, vector<int>(m, 0));
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(u[j]) topHalf[i][j]++;
            if(l[i]) topHalf[i][j]++;
            if(tl[(m-1)+i-j]) topHalf[i][j]++;
            if(tr[i+j]) topHalf[i][j]++;
            if(A[i][j] == '1'){
                u[j] = l[i] = tl[(m-1)+i-j] = tr[i+j] = 1;
            } 
        }
    }
    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            if(d[j]) bottomHalf[i][j]++;
            if(r[i]) bottomHalf[i][j]++;
            if(br[(m-1)+i-j]) bottomHalf[i][j]++;
            if(bl[i+j]) bottomHalf[i][j]++;
            if(A[i][j] == '1'){
                d[j] = r[i] = br[(m-1)+i-j] = bl[i+j] = 1;
            } 
        }
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            ans[i][j] = topHalf[i][j] + bottomHalf[i][j];
        }
    }
    return ans;
}
