// https://leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        ListNode * slow, * fast;
        slow = fast = head;
        do{
            if(fast)
                fast = fast->next;
            else
                return NULL;
            if(fast)
                fast = fast->next;
            else
                return NULL;
            slow = slow->next;
        }while(slow!=fast);
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};