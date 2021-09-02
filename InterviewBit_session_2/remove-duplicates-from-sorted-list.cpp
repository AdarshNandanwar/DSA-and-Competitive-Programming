// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(!A) return A;
    auto ret = A;
    while(A and A->next){
        if(A->val == A->next->val){
            A->next = A->next->next;
        } else {
            A = A->next;
        }
    }
    return ret;
}
