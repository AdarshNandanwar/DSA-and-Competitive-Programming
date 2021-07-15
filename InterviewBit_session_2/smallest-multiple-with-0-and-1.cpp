// https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/

// Method 0 (Same thing as method 1, but dosen't give TLE, garbage IB evaluator):

string Solution::multiple(int A) {
    if(A==1) return "1";
    vector<int> parent(A,-1);
    vector<int> prev_digit(A,-1);
    //BFS
    vector<int> digit = {0, 1};
    queue<int> q;
    q.push(1);
    prev_digit[1] = 1;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(curr==0) break;
        for(int d:digit){
            int next = (curr*10+d)%A;
            if(prev_digit[next]==-1){
                parent[next]=curr;
                prev_digit[next]=d;
                q.push(next);
            }
        }
    }
    // constructing string
    string ans = "";
    for(int rem = 0; rem != -1; rem = parent[rem]){
        ans.push_back('0'+prev_digit[rem]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


// Method 1 (with reconstruction, gives TLE for some random reason, garbage IB evaluator):

string Solution::multiple(int A) {
    if(A == 1) return "1";
    // state = rem
    // m[rem]: {prev rem, last digit added to get this rem}; m[rem][1] also functions as visited
    vector<vector<int>> m(A, {-1, -1}); 
    vector<int> digit = {0, 1};
    queue<int> q;
    q.push(1);
    m[1] = {-1, 1};
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        if(cur == 0) break;
        for(auto &d:digit){
            int r = (10ll*cur+d)%A;
            if(m[r][1] == -1){
                q.push(r);
                m[r] = {cur, d};
            } 
        }
    }
    // constructing string
    string s = "";
    for(int rem = 0; rem != -1; rem = m[rem][0]){
        s.push_back('0'+m[rem][1]);
    }
    reverse(s.begin(), s.end());
    return s;
}

// Method 2 (without reconstruction, MLE):

string Solution::multiple(int A) {
    queue<pair<string, int>> q;
    q.push({"1", 1%A});
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        if(cur.second == 0) return cur.first;
        q.push({cur.first+"1", (10ll*cur.second+1)%A});
        q.push({cur.first+"0", (10ll*cur.second+0)%A});
    }
    return "-1";
}