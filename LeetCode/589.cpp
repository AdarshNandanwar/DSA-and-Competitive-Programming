// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void helper(Node * root, vector<int> & pre){
        if(root == NULL) return;
        pre.push_back(root->val);
        for(int i = 0; i<root->children.size(); i++){
            helper(root->children[i], pre);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> pre;
        helper(root, pre);
        return pre;
    }
};