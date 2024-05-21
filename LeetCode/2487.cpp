// https://leetcode.com/problems/remove-nodes-from-linked-list/

// Method 1 (Recursion, O(n)):

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
class Solution {
    ListNode* helper(ListNode* head, int & rightMax){
        if(head == nullptr){
            return head;
        }
        head->next = helper(head->next, rightMax);
        rightMax = max(rightMax, head->val);
        return head->val < rightMax ? head->next : head;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        int rightMax = INT_MIN;
        return helper(head, rightMax);
    }
};
