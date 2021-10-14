// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

// Method 1 (Iterative, O(n) time, O(1) space):

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
    
    Node* getNextChild(Node * root){
        while(root){
            if(root->left) return root->left;
            if(root->right) return root->right;
            root = root->next;
        }
        return NULL;
    }
    
    Node* connect(Node* root) {
        Node * levelHead = root;
        while(levelHead){
            Node * cur = levelHead;
            while(cur){
                if(cur->left){
                    if(cur->right){
                        cur->left->next = cur->right;
                    } else {
                        cur->left->next = getNextChild(cur->next);
                    }
                }
                if(cur->right){
                    cur->right->next = getNextChild(cur->next);
                }
                cur = cur->next;
            }
            levelHead = getNextChild(levelHead);
        }
        return root;
    }
};

// Method 2 (Level Order Traversal, O(n) time , O(n) space):

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
        if(!root) return root;
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            Node * prev = NULL;
            while(sz--){
                auto cur = q.front();
                q.pop();
                cur->next = prev;
                prev = cur;
                if(cur->right) q.push(cur->right);
                if(cur->left) q.push(cur->left);
            }
        }
        return root;
    }
};