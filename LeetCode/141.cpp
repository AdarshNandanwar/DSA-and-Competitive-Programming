// https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(!head) return head;

        ListNode * slow = head, * fast = head;

        do{
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        } while(fast and slow != fast);

        if(fast == NULL) return 0;
        else return 1;
    }
};