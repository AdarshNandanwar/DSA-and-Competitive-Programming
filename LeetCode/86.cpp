// https://leetcode.com/problems/partition-list/

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
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy;
        dummy.next = head;
        ListNode * p1 = &dummy, * p2 = &dummy, * temp;
        while(p2->next) {
            if(p1->next == p2->next){
                if(p2->next->val < x) p1 = p1->next;
                p2 = p2->next;
            } else {
                if(p2->next->val < x){
                    temp = p1->next;
                    p1->next = p2->next;
                    p2->next = p2->next->next;
                    p1 = p1->next;
                    p1->next = temp;
                } else {
                    p2 = p2->next;
                }
            }
        }
        return dummy.next;
    }
};