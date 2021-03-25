// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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

    // Method 1 (calc pos)

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr  = head;
        int count = 0;
        while(curr != NULL){
            curr = curr->next;
            count++;
        }
        curr = head;
        int pos = count-n-1;
        if(pos == -1){
            return head->next;
        }
        while(pos>0){
            curr = curr->next;
            pos--;
        }
        curr->next = curr->next->next;
        return head;
    }

    // Method 2 (2 pointers)

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * slow = head, * fast = head;
        for(int  i = 0; i<n+1; i++){
            if(fast == NULL){
                return head->next;
            }
            fast = fast->next;
        }
        while(fast!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }

};