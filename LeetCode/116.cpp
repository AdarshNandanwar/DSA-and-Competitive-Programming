// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

// Method 1 (Queue, O(n) time, O(n) space):

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            Node * prev = NULL;
            int sz = q.size();
            while(sz--){
                Node * cur = q.front();
                q.pop();
                cur->next = prev;
                prev = cur;
                if(cur->right){
                    q.push(cur->right);
                }
                if(cur->left){
                    q.push(cur->left);
                }
            }
        }
        return root;
    }
};