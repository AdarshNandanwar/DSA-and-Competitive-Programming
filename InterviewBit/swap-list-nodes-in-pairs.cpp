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
    if(A == NULL) return A;
    ListNode * head = A, * cur = A, * prev = NULL, * temp;
    for(int i = 0; i<2 and cur; i++){
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    head->next = swapPairs(cur);
    return prev;
}
