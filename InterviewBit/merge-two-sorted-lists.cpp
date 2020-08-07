// https://www.interviewbit.com/problems/merge-two-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
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
