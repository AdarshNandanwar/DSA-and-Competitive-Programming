// https://www.interviewbit.com/problems/clone-graph/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
UndirectedGraphNode * helper(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> & visited){
    if(node == NULL) return NULL;
    if(visited.count(node)) return visited[node];
    UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
    visited[node] = root;
    for(auto nbr:node->neighbors) root->neighbors.push_back(helper(nbr, visited));
    return root;
}
 
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> visited;
    return helper(node, visited);
}
