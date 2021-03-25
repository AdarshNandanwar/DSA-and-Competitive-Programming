// https://www.interviewbit.com/problems/remove-nth-node-from-list-end/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode* cur = A;
    int n = 0;
    while(cur){
        n++;
        cur = cur->next;
    }
    
    if(B >= n) return A->next;
    
    int m = n-B-1;
    cur = A;
    while(m--) cur = cur->next;
    cur->next = cur->next->next;
    
    return A;
}
