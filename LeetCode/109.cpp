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

// Method 1 (AVL Tree, works even if input is not sorted, O(nlogn)):

class Solution {
    unordered_map<TreeNode *, int> heights;

    TreeNode * rotateRight(TreeNode* root){
        TreeNode * left = root->left;
        root->left = root->left->right;
        left->right = root;
        heights[root] = 1+max(heights[root->left], heights[root->right]);
        heights[left] = 1+max(heights[left->left], heights[left->right]);
        return left;
    }

    TreeNode * rotateLeft(TreeNode* root){
        TreeNode * right = root->right;
        root->right = root->right->left;
        right->left = root;
        heights[root] = 1+max(heights[root->left], heights[root->right]);
        heights[right] = 1+max(heights[right->left], heights[right->right]);
        return right;
    }

    TreeNode * insert(TreeNode * root, int val){
        if(root == NULL){
            TreeNode * cur = new TreeNode(val);
            heights[cur] = 1;
            return cur;
        }

        if(val <= root->val){
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }
        heights[root] = 1+max(heights[root->left], heights[root->right]);

        int leftHeight = heights[root->left];
        int rightHeight = heights[root->right];
        if(abs(leftHeight-rightHeight) > 1){
            // Imbalance
            if(val <= root->val){
                if(val <= root->left->val){
                    // LL-imbalance
                    root = rotateRight(root);
                } else {
                    // LR-imbalance
                    root->left = rotateLeft(root->left);
                    root = rotateRight(root);
                }
            } else {
                if(val <= root->right->val){
                    // RL-imbalance
                    root->right = rotateRight(root->right);
                    root = rotateLeft(root);
                } else {
                    // RR-imbalance
                    root = rotateLeft(root);
                }
            }
        }
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode * root;
        while(head){
            root = insert(root, head->val);
            head = head->next;
        }
        return root;
    }
};

// Method 2 (Recursion, works since input is sorted, O(nlogn)):

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

// Method 3 (Recursion, Alternate Code (Dummy Variable), works since input is sorted, O(nlogn)):

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
