// https://leetcode.com/problems/reorder-list/

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
    ListNode * revList(ListNode * head){
        if(head == NULL) return head;
        ListNode * prev = NULL, * cur = head, * temp;
        while(cur){
            temp = cur->next;
            cur->next=  prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head == NULL) return;
        int n = 0;
        ListNode * cur = head, * temp;
        while(cur){
            cur = cur->next;
            n++;
        }

        int m = (n-1)/2;
        cur = head;
        while(m--) cur = cur->next;

        cur->next = revList(cur->next);
        ListNode * p1 = head, * p2 = cur->next;
        cur->next = NULL;

        while(p1 and p2){
            temp = p1->next;
            p1->next = p2;
            p1 = p1->next;
            p2 = p2->next;
            p1->next = temp;
            p1 = p1->next;
        }
    }
};