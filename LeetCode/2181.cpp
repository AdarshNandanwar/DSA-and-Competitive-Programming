// https://leetcode.com/problems/merge-nodes-in-between-zeros/

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
    ListNode* helper(ListNode * head){
        if(head == nullptr){
            return head;
        }
        
        head->next = helper(head->next);

        if(head->val == 0){
            return head;
        } else {
            head->next->val += head->val;
            return head->next;
        }
    }
public:
    ListNode* mergeNodes(ListNode* head) {
        return helper(head->next);
    }
};
