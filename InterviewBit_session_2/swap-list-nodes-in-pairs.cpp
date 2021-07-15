// https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if(!A or !A->next) return A;
    auto temp = A->next;
    A->next = A->next->next;
    temp->next = A;
    A->next = swapPairs(A->next);
    return temp;
}
