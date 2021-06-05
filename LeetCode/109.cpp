// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return new TreeNode(head->val);

        ListNode * slow = head, * fast = head, * prev = head;
        while(fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast->next) fast = fast->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->right = sortedListToBST(slow->next);
        prev->next = NULL;
        root->left = sortedListToBST(head);
        return root;
    }
};

// Alternate Code (Dummy Variable):

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        
        ListNode dummy(0, head);
        ListNode * slow = &dummy, * fast = &dummy;
        
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode * root = new TreeNode();
        root->val = slow->next->val;
        root->right = sortedListToBST(slow->next->next);
        slow->next = NULL;
        root->left = sortedListToBST(dummy.next);
        
        return root;
    }
};