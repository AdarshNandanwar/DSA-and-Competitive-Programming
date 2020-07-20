// https://www.interviewbit.com/problems/sum-of-fibonacci-numbers/

int fib(int n, vector<int> & fn){
    if(n == 0 or n == 1) return fn[n] = n;
    if(fn[n] != -1) return fn[n];
    return fn[n] = fib(n-1, fn)+fib(n-2, fn);
}

int bfs(int n, vector<int> & fn){
    
    queue<pair<int, int>> q;
    unordered_set<int> visited;
    int cur, lb = lower_bound(fn.begin(), fn.end(), n)-fn.begin(), sz, count = 0, index;
    for(int i = lb; i>=2; i--) if(i<47 and !visited.count(fn[i])){
        visited.insert(fn[i]);
        if(fn[i]<n) q.push({fn[i], i});
        else if(fn[i]==n) return count+1;
    } 
    while(!q.empty()){
        count++;
        sz = q.size();
        for(int i = 0; i<sz; i++){
            cur = q.front().first;
            index = q.front().second;
            q.pop();
            for(int j = index; j>=2; j--){
                if(!visited.count(cur+fn[j])){
                    visited.insert(cur+fn[j]);
                    if(cur+fn[j]<n) q.push({cur+fn[j], j});
                    else if(cur+fn[j]==n) return count+1;
                } 
            } 
        }
    }
    return -1;
}

int dfs(int n, vector<int> & fn){
    
    stack<pair<int, int>> st;
    unordered_set<int> visited;
    int cur, lb = lower_bound(fn.begin(), fn.end(), n)-fn.begin(), sz, index;
    for(int i = lb; i>=2; i--) if(i<47 and !visited.count(fn[i])){
        visited.insert(fn[i]);
        if(fn[i]<n) st.push({fn[i], i});
        else if(fn[i]==n) return 1;
        cout<<"push "<<fn[i]<<endl;
    } 
    while(!st.empty()){
        cur = st.top().first;
        index = st.top().second;
        st.pop();
        cout<<"pop "<<cur<<endl;
        for(int j = index; j>=2; j--){
            if(!visited.count(cur+fn[j])){
                visited.insert(cur+fn[j]);
                if(cur+fn[j]<n) st.push({cur+fn[j], j});
                else if(cur+fn[j]==n) return st.size()+1;
                cout<<"push "<<cur+fn[j]<<endl;
            } 
        } 
    }
    return -1;
}

int Solution::fibsum(int A) {
    if(A <= 3) return 1;
    vector<int> fn(47, -1);
    fib(46, fn);
    // return bfs(A, fn);
    return dfs(A, fn);
}
