// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

#include<bits/stdc++.h>
using namespace std;

int calculateSum(int ** c_mat, int y, int x, int len){
    // Assuming never out of bounds
    // a b
    // c d
    int a, b, c, d = c_mat[y+len-1][x+len-1];
    if(y == 0){
        a = 0;
        b = 0;
        if(x == 0){
            c = 0;
        } else {
            c = c_mat[y+len-1][x-1];
        }
    } else {
        b = c_mat[y-1][x+len-1];
        if(x == 0){
            a = 0;
            c = 0;
        } else {
            a = c_mat[y-1][x-1];
            c = c_mat[y+len-1][x-1];
        }
    }
    return d-b-c+a;        
}


int ** calculate_c_mat(vector<vector<int>> mat){
    int ** c_mat = new int*[mat.size()];
    
    for (int i = 0; i < mat.size(); i++)
    {
        c_mat[i] = new int[mat[0].size()];
    }
    int n = mat.size(), m = mat[0].size();
    c_mat[0][0] = mat[0][0];
    for(int i = 1; i<n; i++){
        c_mat[i][0] = c_mat[i-1][0]+mat[i][0];
    }
    for(int i = 1; i<m; i++){
        c_mat[0][i] = c_mat[0][i-1]+mat[0][i];
    }
    for(int i = 1; i<n; i++){
        for(int j = 1; j<m; j++){
            c_mat[i][j] = mat[i][j]+c_mat[i-1][j]+c_mat[i][j-1]-c_mat[i-1][j-1];
        }
    }
    return c_mat;
}

int findLen(int ** c_mat,int n, int m, int y, int x, int threshold){
    // Binary Search
    
    // FFFTTT
    // p(mid): calculateSum(c_mat, y, x, mid)>threshold
    // Last F
    
    int lo = 1, hi = min(n-y, m-x), mid;
    while(lo<hi){
        mid = lo+(hi-lo+1)/2;
        if(calculateSum(c_mat, y, x, mid)>threshold){
            hi = mid-1;
        } else {
            lo = mid;
        }
    }
    if(!(calculateSum(c_mat, y, x, lo)>threshold)){
        return lo;
    } else {
        return 0;
    }
}

int maxSideLength(vector<vector<int>>& mat, int threshold) {
    if(mat.size() == 0){
        return 0;
    } else if(mat[0].size() == 0){
        return 0;
    }
    int ** c_mat = calculate_c_mat(mat);
    int max_len = 0, n = mat.size(), m = mat[0].size();

    for(int i = 0; i<n; i++){
        for(int j =0; j<m; j++){
            int len = findLen(c_mat, mat.size(), mat[0].size(), i, j, threshold);
            max_len = max(max_len, len);
        }
    }
    return max_len;
}

int main(){
    vector<vector<int>> mat{
        // {1,1,3,2,4,3,2},
        // {1,1,5,2,6,3,7},
        // {1,1,2,2,10,3,2}

        {1,1,1,1},
        {1,0,0,0},
        {1,0,0,0},
        {1,0,0,0},
    };
    int threshold = 6;
    cout<<maxSideLength(mat, threshold)<<endl;
}