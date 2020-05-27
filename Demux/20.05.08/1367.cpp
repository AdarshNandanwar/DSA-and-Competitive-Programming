// https://leetcode.com/problems/linked-list-in-binary-tree/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
class Solution {
public:
    
    bool helper(ListNode* head, TreeNode* root, ListNode* curr, unordered_map<TreeNode *, bool> & m){
        if(curr == NULL) return true;
        if(root == NULL) return false;
        if(root->val == curr->val)
            if(helper(head, root->left, curr->next, m) or helper(head, root->right, curr->next, m)) 
                return true;
        if(m[root]) return false;
        if(helper(head, root->left, head, m) or helper(head, root->right, head, m)) 
            return true;
        m[root] = true;
        return false;
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        unordered_map<TreeNode *, bool> m;
        return helper(head, root, head, m);   
    }
};