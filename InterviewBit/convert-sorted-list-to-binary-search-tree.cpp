// https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A == NULL) return NULL;
    if(A->next == NULL) return new TreeNode(A->val);
    
    ListNode * slow = A, * fast = A, * prev = A;
    while(fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next;
        if(fast->next) fast = fast->next;
    }
    TreeNode* root = new TreeNode(slow->val);
    root->right = sortedListToBST(slow->next);
    prev->next = NULL;
    root->left = sortedListToBST(A);
    return root;
}
