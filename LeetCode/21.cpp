// https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
        ListNode * head = NULL, * cur = head;
        while(A and B){
            if(A->val < B->val){
                if(head == NULL){
                    head = cur = new ListNode(A->val);
                } else {
                    cur->next = new ListNode(A->val);
                    cur = cur->next;
                }
                A = A->next;
            } else {
                if(head == NULL){
                    head = cur = new ListNode(B->val);
                } else {
                    cur->next = new ListNode(B->val);
                    cur = cur->next;
                }
                B = B->next;
            }
        }
        while(A){
            if(head == NULL){
                head = cur = new ListNode(A->val);
            } else {
                cur->next = new ListNode(A->val);
                cur = cur->next;
            }
            A = A->next;
        }
        while(B){
            if(head == NULL){
                head = cur = new ListNode(B->val);
            } else {
                cur->next = new ListNode(B->val);
                cur = cur->next;
            }
            B = B->next;
        }
        return head;
    }
};