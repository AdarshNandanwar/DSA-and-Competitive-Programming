// https://www.interviewbit.com/problems/k-reverse-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(A == NULL) return A;
    ListNode * head = A, * cur = A, * prev = NULL, * temp;
    for(int i = 0; i<B and cur; i++){
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    head->next = reverseList(cur, B);
    return prev;
}
