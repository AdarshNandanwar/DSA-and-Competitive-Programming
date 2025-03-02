// https://leetcode.com/problems/linked-list-in-binary-tree/

// Method 1 (Recursion, O(n*m));

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
    bool helper(ListNode* head, TreeNode* root, bool isBeginning) {
        if(head == nullptr){
            return true;
        }
        if(root == nullptr){
            return false;
        }
        
        bool response = false;
        if(head->val == root->val){
            response |= helper(head->next, root->left, false);
            response |= helper(head->next, root->right, false);
        }

        if(isBeginning){
            response |= helper(head, root->left, true);
            response |= helper(head, root->right, true);
        }

        return response;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return helper(head, root, true);
    }
};
