// https://leetcode.com/problems/word-ladder-ii/

// Method 1 (path reconstruction, x100 faster than Method 2, BFS on path):

class Solution {
public:
    
    bool is_nbr(const string & a, const string & b){
        if(a.length() != b.length()) return 0;
        int count = 0;
        for(int i = 0; i<a.length(); i++){
            if(a[i]!=b[i]) count++;
            if(count > 1) return 0;
        }
        return count == 1;
    }

    void generate(int x, unordered_map<int, unordered_set<int>> & prev, vector<vector<string>> & ans, vector<string> & cur, vector<string> & sv){
        if(x == -1){
            ans.push_back(cur);
            return;
        }
        cur.push_back(sv[x]);
        for(auto &i:prev[x]){
            generate(i, prev, ans, cur, sv);
        }
        cur.pop_back();
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        if(!s.count(endWord)) return {};
        s.insert(beginWord);
        wordList.clear();
        for(auto &i:s) wordList.push_back(i);
        int n = wordList.size(), st_index = 0, end_index = 0;
        vector<vector<int>> adj(n, vector<int>(0));
        vector<bool> visited(n, 0);
        for(int i = 0; i<n; i++){
            if(wordList[i] == beginWord) st_index = i;
            if(wordList[i] == endWord) end_index = i;
            for(int j = 0; j<n; j++){
                if(i!=j and is_nbr(wordList[i], wordList[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        unordered_map<int, unordered_set<int>> prev;
        vector<vector<string>> ans;
        queue<int> q;
        q.push(st_index);
        visited[st_index] = 1;
        prev[st_index] = {-1};
        while(1){
            bool found = 0;
            unordered_set<int> to_remove;
            if(q.empty()) return {};
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                if(cur == end_index){
                    found = 1;
                    break;
                } 
                for(auto &nbr:adj[cur]){
                    if(!visited[nbr]){
                        to_remove.insert(nbr);
                        prev[nbr].insert(cur);
                    }
                }
            }
            if(found) break;
            for(auto &d:to_remove){
                q.push(d);
                visited[d] = 1;
            }
        }
        // generate ans
        vector<string> temp = {};
        generate(end_index, prev, ans, temp, wordList);
        for(auto &i:ans) reverse(i.begin(), i.end());
        return ans;
    }
};

// Method 2 (BFS on path):

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        // creating unique wordList with beginWord included
        
        unordered_set<string> us;
        for(auto i:wordList) us.insert(i);
        us.insert(beginWord);
        vector<string> uniqueDict(us.begin(), us.end());

        // creating the graph
        
        int n = uniqueDict.size();
        vector<vector<int>> adjList(n);
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int diff = 0;
                for(int k = 0; k<beginWord.length(); k++) diff += (uniqueDict[i][k] != uniqueDict[j][k]);
                if(diff == 1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                } 
            }
        }

        vector<vector<int>> resInd;

        // BFS

        int len = 1, startIndex = find(uniqueDict.begin(), uniqueDict.end(), beginWord)-uniqueDict.begin();
        bool found = 0;
        vector<bool> visited(n);
        queue<vector<int>> q;    // current path
        q.push({startIndex});
        while(!q.empty()){
            int sz = q.size();
            unordered_set<int> curVisited;
            for(int i = 0; i<sz; i++){
                auto cur = q.front();
                q.pop();
                if(uniqueDict[cur.back()] == endWord){
                    found = 1;
                    resInd.push_back(cur);
                } else {
                    for(auto nbr:adjList[cur.back()]){
                        if(!visited[nbr]){
                            curVisited.insert(nbr);
                            auto v = cur;
                            v.push_back(nbr);
                            q.push(v);
                        }
                    }
                }
            }
            if(found) break;
            for(auto i:curVisited) visited[i] = 1;
            len++;
        }

        // converting indexes to string

        vector<vector<string>> res;
        for(auto i:resInd){
            vector<string> v;
            for(auto j:i) v.push_back(uniqueDict[j]);
            res.push_back(v);
        }

        return res;
    }
};