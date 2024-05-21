// https://leetcode.com/problems/open-the-lock/

// Method 1 (BFS with int, O(Misc + E + V) = O(d + 10^4 + 8^10^4) = O(d)):

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int targetNode = stoi(target);
        unordered_set<int> deadendNodes;
        for(string & deadend:deadends){
            deadendNodes.insert(stoi(deadend));
        }
        int turns = 0;
        vector<int> visited(10000, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int cur = q.front();
                q.pop();
                if(cur == targetNode){
                    return turns;
                }
                if(deadendNodes.count(cur)){
                    continue;
                }
                for(int place=1; place<10000; place*=10){
                    int digit = (cur/place)%10;

                    int upDigit = (digit+1)%10;
                    int upNext = cur-(digit*place)+(upDigit*place);
                    if(!visited[upNext]){
                        q.push(upNext);
                        visited[upNext] = true;
                    }

                    int downDigit = (digit+9)%10;
                    int downNext = cur-(digit*place)+(downDigit*place);
                    if(!visited[downNext]){
                        q.push(downNext);
                        visited[downNext] = true;
                    }
                }
            }
            turns++;
        }
        return -1;
    }
};

// Method 2 (BFS with string, O(10^8)):

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
