// https://leetcode.com/problems/n-ary-tree-postorder-traversal/

// Method 1 (Recursion, O(n)):

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
    void traverse(Node * root, vector<int> & path){
        if(root == nullptr){
            return;
        }
        for(auto child:root->children){
            traverse(child, path);
        }
        path.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> path;
        traverse(root, path);
        return path;
    }
};
