// https://leetcode.com/problems/friend-circles/

class Solution {
public:
    
    void dfs(vector<vector<int>>& M, int cur, vector<bool> & visited){
        
        if(visited[cur]) return;
        
        stack<int> st;
        st.push(cur);
        while(!st.empty()){
            int person = st.top();
            st.pop();
            for(int i = 0; i<M.size(); i++){
                if(M[person][i] and !visited[i]){
                    st.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        
        vector<bool> visited(M.size(), false);
        int count = 0;
        for(int i = 0; i<M.size(); i++){
            if(!visited[i]){
                dfs(M, i, visited);
                count++;
            }
        }
        return count;
    }
};