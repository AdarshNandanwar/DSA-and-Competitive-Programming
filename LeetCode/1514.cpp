// https://leetcode.com/problems/path-with-maximum-probability/

// Method 1 (Dijkstra's Algorithm, O(elogv)):

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // {node, prob}
        vector<vector<pair<int, double>>> nbrs(n, vector<pair<int, double>>(0));
        for(auto i=0; i<edges.size(); i++){
            nbrs[edges[i][0]].push_back({edges[i][1], succProb[i]});
            nbrs[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> prob(n, 0);
        prob[start] = 1;
        // {prob, node}
        priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
        pq.push({1, start});
        while(!pq.empty()){
            auto curN = pq.top().second;
            auto curP = pq.top().first;
            pq.pop();
            if(prob[curN] > curP) continue;
            for(auto &nbr:nbrs[curN]){
                int nbrN = nbr.first;
                double nbrP = prob[curN]*nbr.second;
                if(prob[nbrN] < nbrP){
                    prob[nbrN] = nbrP;
                    pq.push({prob[nbrN], nbrN});
                }
            }
        }
        return prob[end];
    }
};

// Method 2 (Dijkstra's Logic with less space and early stop, O(elogv)):

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // {weight, nbr}
        vector<vector<pair<double, int>>> nbrs(n);
        int e = edges.size();
        for(int i=0; i<e; i++){
            nbrs[edges[i][0]].push_back(make_pair(succProb[i], edges[i][1]));
            nbrs[edges[i][1]].push_back(make_pair(succProb[i], edges[i][0]));
        }

        // {weight, nbr}
        priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
        vector<bool> visited(n);
        pq.push(make_pair(1, start_node));
        while(!pq.empty()){
            auto top = pq.top();
            int cur = top.second;
            double prob = top.first;
            pq.pop();
            if(cur == end_node){
                return prob;
            }
            if(visited[cur]){
                continue;
            }
            visited[cur] = true;
            for(auto nbr:nbrs[cur]){
                pq.push(make_pair(prob * nbr.first, nbr.second));
            }
        }

        return 0;
    }
};

// Method 2 (Dijkstra's Logic with less space and early stop, Custom Comparator, O(elogv)):

struct Cmp{
    bool operator()(const pair<int, double> & a, const pair<int, double> & b){
        return a.second < b.second;
    }
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int, double>>> adjList(n);
        for(int i = 0; i<edges.size(); i++){
            adjList[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adjList[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<bool> visited(n, 0);
        
        priority_queue<pair<int, double>, vector<pair<int, double>>, Cmp> pq;
        
        pq.push({start, 1.0});
        visited[start] = 1;
        
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            visited[cur.first] = 1;
            if(cur.first == end) return cur.second;
            for(auto nbr:adjList[cur.first]){
                if(!visited[nbr.first]){
                    pq.push({nbr.first, cur.second*nbr.second});
                }
            }
        }
        
        return 0;
    }
};

// Attempt 1 (DFS, TLE, O(2^n)):

double dfs(vector<vector<pair<int, double>>> & adjList, int cur, int & end, vector<bool> & visited){
    if(cur == end) return 1;
    double res = 0;
    for(auto nbr:adjList[cur]){
        if(visited[nbr.first]) continue;
        visited[nbr.first] = 1;
        res = max(res, (double)(nbr.second*dfs(adjList, nbr.first, end, visited)));
        visited[nbr.first] = 0;
    }
    return res;
}


class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int, double>>> adjList(n);
        for(int i = 0; i<edges.size(); i++){
            adjList[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adjList[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<bool> visited(n, 0);
        
        return dfs(adjList, start, end, visited);
    }
};