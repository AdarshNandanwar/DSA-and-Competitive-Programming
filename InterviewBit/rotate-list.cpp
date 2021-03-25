// https://www.interviewbit.com/problems/rotate-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    if(A == NULL) return NULL;
    int n = 0;
    ListNode* cur = A, * newHead;
    while(cur){
        cur = cur->next;
        n++;
    }
    B = B%n;
    if(B == 0) return A;
    int m = n-B-1;
    cur = A;
    while(m--) cur = cur->next;
    newHead = cur->next;
    cur->next = NULL;
    cur = newHead;
    while(cur->next) cur = cur->next;
    cur->next = A;
    return newHead;
}
