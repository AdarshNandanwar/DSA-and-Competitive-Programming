// https://leetcode.com/problems/open-the-lock/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // BFS
        unordered_set<string> visited(deadends.begin(), deadends.end());
        int steps = 0;
        string start = "0000";
        queue<string> q;
        if(visited.count(start)) return -1;
        q.push(start);
        visited.insert(start);
        while(1){
            vector<string> v;
            while(!q.empty()){
                if(q.front() == target) return steps;
                v.push_back(q.front());
                q.pop();
            }
            if(v.empty()) break;
            for(auto & s:v){
                for(int i = 0; i<4; i++){
                    s[i] = s[i] == '0' ? '9' : s[i]-1;
                    if(!visited.count(s)){
                        q.push(s);
                        visited.insert(s);
                    } 
                    s[i] = s[i] == '9' ? '0' : s[i]+1;
                    s[i] = s[i] == '9' ? '0' : s[i]+1;
                    if(!visited.count(s)){
                        q.push(s);
                        visited.insert(s);
                    } 
                    s[i] = s[i] == '0' ? '9' : s[i]-1;
                }
            }
            steps++;
        }
        return -1;
    }
};

// Alternate Code

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // BFS
        unordered_set<string> visited(deadends.begin(), deadends.end());
        int steps = 0;
        string start = "0000";
        // {string, steps}
        queue<pair<string, int>> q;
        if(visited.count(start)) return -1;
        q.push({start, 0});
        visited.insert(start);
        while(!q.empty()){
            string s = q.front().first;
            int steps = q.front().second;
            if(s == target) return steps;
            q.pop();
            
            for(int i = 0; i<4; i++){
                s[i] = s[i] == '0' ? '9' : s[i]-1;
                if(!visited.count(s)){
                    q.push({s, steps+1});
                    visited.insert(s);
                } 
                s[i] = s[i] == '9' ? '0' : s[i]+1;
                s[i] = s[i] == '9' ? '0' : s[i]+1;
                if(!visited.count(s)){
                    q.push({s, steps+1});
                    visited.insert(s);
                } 
                s[i] = s[i] == '0' ? '9' : s[i]-1;
            }
        }
        return -1;
    }
};