// https://leetcode.com/problems/reconstruct-itinerary/

// Method 1 (Solution, Using Eulerian path Properties, Hierholzer’s Algorithm):

// In Eulerian paths, there must exist a start node(which is JFK in this problem) and a end node.
// End node can be start node or another node.
// end node is start node iff all nodes has even degree.
// end node is another node iff there is another odd degree node and start node has an odd degree.

// The idea is to keep following unused edges and removing them until we get stuck. 
// Once we get stuck, we backtrack to the nearest vertex in our current path that has unused edges, 
// and we repeat the process until all the edges have been used. We can use another container to maintain the final path.

vector<string> findItinerary(vector<pair<string, string>> tickets) {
    for (auto ticket : tickets)
        targets[ticket.first].insert(ticket.second);
    visit("JFK");
    return vector<string>(route.rbegin(), route.rend());
}

map<string, multiset<string>> targets;
vector<string> route;

void visit(string airport) {
    while (targets[airport].size()) {
        string next = *targets[airport].begin();
        targets[airport].erase(targets[airport].begin());
        visit(next);
    }
    route.push_back(airport);
}

// Method 2 (DFS):

bool dfs(int n, unordered_map<string, vector<string>> & g,unordered_map<string, int> & edgeCount, string pos, vector<string> & res){
    
    if(res.size() == n+1) return true;
    
    string key;
    for(auto des:g[pos]){
        key = pos+des;
        if(edgeCount[key]){
            res.push_back(des);
            edgeCount[key]--;
            if(dfs(n, g, edgeCount, des, res))
                return true;
            edgeCount[key]++;
            res.pop_back();
        }
    }
    return false;
}

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        int n = tickets.size();
        if(n == 0) return vector<string>();
        string cur;
        
        unordered_map<string, vector<string>> g;       // ordered set
        unordered_map<string, int> edgeCount;           // visited for edges
        
        for(auto tkt:tickets){
            g[tkt[0]].push_back(tkt[1]);
            edgeCount[tkt[0]+tkt[1]]++;
        }
        for(auto & i:g){
            sort(i.second.begin(), i.second.end());
        }
        
        vector<string> res;
        res.push_back("JFK");        
        
        dfs(n, g, edgeCount, "JFK", res);
        
        return res;
    }
};