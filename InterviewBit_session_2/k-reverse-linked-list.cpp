// https://www.interviewbit.com/problems/k-reverse-linked-list/

// Method 1 (Recursion):

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(!A) return A;
    ListNode * prev = NULL, * p = A;
    for(int i = 0; i<B and p; i++){
        auto temp = p->next;
        p->next = prev;
        prev = p;
        p = temp;
    }
    A->next = reverseList(p, B);
    return prev;
}
