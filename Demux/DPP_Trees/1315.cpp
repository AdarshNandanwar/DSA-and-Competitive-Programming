// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct Node{
    TreeNode * tn;
    bool p, gp;
    Node(TreeNode * tn, bool p, bool gp):tn(tn), p(p), gp(gp){};
};

class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        if(!root) return 0;
        int sum = 0, sz;
        queue<Node *> q;
        q.push(new Node(root, false, false));
        while(!q.empty()){
            sz = q.size();
            for(int i = 0; i<sz; i++){
                Node * cur = q.front();
                q.pop();
                if(cur->gp) sum += cur->tn->val;
                if(cur->tn->left) q.push(new Node(cur->tn->left, cur->tn->val%2 == 0, cur->p));
                if(cur->tn->right) q.push(new Node(cur->tn->right, cur->tn->val%2 == 0, cur->p));
            }
        }
        return sum;
    }
};