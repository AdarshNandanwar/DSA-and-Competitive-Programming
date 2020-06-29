// https://leetcode.com/problems/beautiful-arrangement/

class Solution {
public:
    
    void solve(int & n, int index, vector<bool> & visited, int & count){
        if(index == n){
            count++;
            return;
        }
        
        for(int i = 0; i< n; i++){
            if(!visited[i] and ((i+1)%(index+1) == 0 or (index+1)%(i+1) == 0)){
                visited[i] = true;
                solve(n, index+1, visited, count);
                visited[i] = false;
            }
        }
    }
    
    int countArrangement(int N) {
        vector<bool> visited(N);
        int count = 0;
        solve(N, 0, visited, count);
        return count;
    }
};