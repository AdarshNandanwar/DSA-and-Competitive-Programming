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
    ListNode dummy(0);
    auto cur = &dummy;
    while(A and B){
        if(A->val > B->val) swap(A, B);
        cur->next = A;
        A = A->next;
        cur = cur->next;
    }
    while(A){
        cur->next = A;
        A = A->next;
        cur = cur->next;
    }
    while(B){
        cur->next = B;
        B = B->next;
        cur = cur->next;
    }
    return dummy.next;
}
