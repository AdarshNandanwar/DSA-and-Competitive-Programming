// https://www.interviewbit.com/problems/water-flow/

vector<int> dir = {0, -1, 0, 1, 0};

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    if(n == 0) return 0;
    int m = A[0].size();

    vector<vector<int>> visitedBlue(n, vector<int>(m, 0));

    queue<vector<int>> q;
    for(int i = 0; i<n; i++){
        q.push({i, -1});
    }
    for(int j = 0; j<m; j++){
        q.push({-1, j});
    }

    while(!q.empty()){
        auto cur = q.front();
        int i = cur[0], j = cur[1];
        int curVal = -1;
        if(0<=i and i<n and 0<=j and j<m) curVal = A[i][j];
        q.pop();
        for(int k = 0; k<4; k++){
            int I = i+dir[k], J = j+dir[k+1];
            if(0<=I and I<n and 0<=J and J<m and !visitedBlue[I][J] and A[I][J]>=curVal){
                visitedBlue[I][J] = 1;
                q.push({I, J});
            }
        }
    }

    vector<vector<int>> visitedRed(n, vector<int>(m, 0));

    for(int i = 0; i<n; i++){
        q.push({i, m});
    }
    for(int j = 0; j<m; j++){
        q.push({n, j});
    }

    while(!q.empty()){
        auto cur = q.front();
        int i = cur[0], j = cur[1];
        int curVal = -1;
        if(0<=i and i<n and 0<=j and j<m) curVal = A[i][j];
        q.pop();
        for(int k = 0; k<4; k++){
            int I = i+dir[k], J = j+dir[k+1];
            if(0<=I and I<n and 0<=J and J<m and !visitedRed[I][J] and A[I][J]>=curVal){
                visitedRed[I][J] = 1;
                q.push({I, J});
            }
        }
    }

    int res = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(visitedBlue[i][j] and visitedRed[i][j]) res++;
        }
    }
    return res;
}
