// https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node * helper(Node *node, unordered_map<Node *, Node *> & visited){
        if(node == NULL) return NULL;
        if(visited.count(node)) return visited[node];
        Node *root = new Node(node->val);
        visited[node] = root;
        for(auto nbr:node->neighbors) root->neighbors.push_back(helper(nbr, visited));
        return root;
    }
    
    Node* cloneGraph(Node* node) {
        unordered_map<Node *, Node *> visited;
        return helper(node, visited);
    }
};