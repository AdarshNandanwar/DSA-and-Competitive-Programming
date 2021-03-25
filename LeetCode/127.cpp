// https://leetcode.com/problems/word-ladder/

// Method 2 (index BFS):

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        
        int n = wordList.size(), diff;
        vector<vector<int>> adjList(n);
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                diff = 0;
                for(int k = 0; k<beginWord.length(); k++) diff += (wordList[i][k] != wordList[j][k]);
                if(diff == 1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                } 
            }
        }

        // BFS

        int count = 1;
        vector<int> visited(n);
        queue<int> q;
        q.push(n-1);
        visited[n-1] = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i<sz; i++){
                auto cur = q.front();
                q.pop();
                if(wordList[cur] == endWord) return count;
                for(auto nbr:adjList[cur]){
                    if(!visited[nbr]){
                        visited[nbr] = 1;
                        q.push(nbr);
                    }
                }
            }
            count++;
        }
        return 0;
    }
};

// Method 2 (String BFS):

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_map<string, vector<string>> adjList;

        int n = wordList.size(), diff;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                diff = 0;
                for(int k = 0; k<beginWord.length(); k++) diff += (wordList[i][k] != wordList[j][k]);
                if(diff == 1){
                    adjList[wordList[i]].push_back(wordList[j]);
                    adjList[wordList[j]].push_back(wordList[i]);
                } 
            }
        }

        // BFS

        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        int count = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i<sz; i++){
                auto cur = q.front();
                q.pop();
                if(cur == endWord) return count;
                for(auto nbr:adjList[cur]){
                    if(!visited.count(nbr)){
                        visited.insert(nbr);
                        q.push(nbr);
                    }
                }
            }
            count++;
        }
        return 0;
    }
};