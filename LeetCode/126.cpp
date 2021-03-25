// https://leetcode.com/problems/word-ladder-ii/

// Method (BFS on path):

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