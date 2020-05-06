// https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        int c1 = 1, c2 = 1;
        ListNode * p1, * p2;
        p1 = head; p2 = head->next;
        while(p2!=NULL && p2->next!=NULL){
            ListNode * n1 = new ListNode(p2->next->val, p1->next);
            p1->next = n1;
            p2->next = p2->next->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        return head;
    }
};