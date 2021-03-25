// https://www.interviewbit.com/problems/cycle-in-undirected-graph/

// Method 1 (DFS, O(E+V)):

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adjList(A);
    for(auto i:B){
        adjList[i[0]-1].push_back(i[1]-1);
        adjList[i[1]-1].push_back(i[0]-1);
    }
    
    // dfs
    vector<bool> visited(A, 0);
    // {cur, parent}
    stack<pair<int, int>> st;
    for(int i = 0; i<A; i++){
        if(visited[i]) continue;
        visited[i] = 1;
        st.push({i, -1});
        while(!st.empty()){
            auto cur = st.top().first;
            auto prev = st.top().second;
            st.pop();
            for(auto nbr:adjList[cur]){
                if(nbr == prev) continue;
                if(visited[nbr]) return 1;
                visited[nbr] = 1;
                st.push({nbr, cur});
            }
        }
    }
    return 0;
}
