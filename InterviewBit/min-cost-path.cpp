// https://www.interviewbit.com/problems/min-cost-path/

// Method 1 (Dijkstra's Algo, O(ElogV)):

vector<int> dir = {0, -1, 0, 1, 0};

int Solution::solve(int A, int B, vector<string> &C) {
    if(A == 0 or B == 0) return 0;
    vector<vector<int>> d(A, vector<int>(B, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});
    d[0][0] = 0;
    while(!pq.empty()){
        int sz = pq.size();
        while(sz--){
            auto cur = pq.top();
            int curC = cur.first;
            pq.pop();
            if(cur.second.first == A-1 and cur.second.second == B-1) return curC;
            if(cur.second.first != 0 and cur.second.second != 0 and d[cur.second.first][cur.second.second] < cur.first) continue;
            for(int x = 0; x<4; x++){
                int i = cur.second.first+dir[x], j = cur.second.second+dir[x+1];
                if(i<0 or i>=A or j<0 or j>=B) continue;
                char c = C[cur.second.first][cur.second.second];
                bool isSame = (x==0 and c=='L') or (x==1 and c=='U') or (x==2 and c=='R') or (x==3 and c=='D');
                if(d[i][j] > (!isSame)+curC){
                    d[i][j] = (!isSame)+curC;
                    pq.push({(!isSame)+curC, {i, j}});
                }
            }
        }
    }
    return A+B-2;
}
