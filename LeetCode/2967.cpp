// https://leetcode.com/problems/minimum-cost-to-convert-string-i/

// Method 1 (Dijkstra's Algorithm, O(n + 26⋅(26+m)log26) = O(n+m) time, O(m) space):

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        // {cost, nbr}
        vector<vector<pair<int, int>>> nbrs(26);
        for(int i=0; i<original.size(); i++){
            nbrs[original[i]-'a'].push_back(make_pair(cost[i], changed[i]-'a'));
        }

        vector<vector<int>> charCost(26);
        for(int i=0; i<26; i++){
            vector<int> dist(26, INT_MAX);
            // {cumCost, cur}
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push(make_pair(0, i));
            while(!pq.empty()){
                auto t = pq.top();
                pq.pop();
                int cur = t.second;
                int curCost = t.first;
                if(dist[cur] <= curCost){
                    continue;
                }
                dist[cur] = curCost;
                for(auto nbr:nbrs[cur]){
                    int nbrCost = curCost + nbr.first;
                    if(nbrCost < dist[nbr.second]){
                        pq.push(make_pair(nbrCost, nbr.second));
                    }
                }
            }
            charCost[i] = dist;
        }

        long long minCost = 0;
        for(int i=0; i<source.size(); i++){
            if(charCost[source[i]-'a'][target[i]-'a'] == INT_MAX){
                return -1;
            }
            minCost += charCost[source[i]-'a'][target[i]-'a'];
        }
        return minCost;
    }
};
