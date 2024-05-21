// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/

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
    ListNode* helper(ListNode* head, int & carry) {
        if(head == nullptr){
            return head;
        }
        head->next = helper(head->next, carry);
        int sum = head->val + head->val + carry;
        carry = sum / 10;
        head->val = sum % 10;
        return head;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        ListNode * result = helper(head, carry);
        return carry ? new ListNode(carry, head) : result;
    }
};
