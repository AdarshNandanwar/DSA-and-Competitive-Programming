// https://www.interviewbit.com/problems/reverse-link-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode * reverseList(ListNode * head, int n){
    ListNode * next = NULL, * cur = head, * prev = NULL;
    while(n--){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head->next = cur;
    return prev;
}
 
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode * head = A, * prev = NULL;
    for(int i = 0; i<B-1; i++){
        prev = A;
        A = A->next;
    }
    if(prev) prev->next = reverseList(A, C-B+1);
    else head = reverseList(A, C-B+1);
    return head;
}
