// https://www.interviewbit.com/problems/palindrome-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode * revList(ListNode * head){
    ListNode * cur = head, * prev = NULL, * temp = NULL;
    while(cur){
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}
 
int Solution::lPalin(ListNode* A) {
    if(!A) return 1;
    ListNode * slow = A, * fast = A, * prev = NULL;
    do{
        prev = slow;
        slow = slow->next;
        fast = fast->next;
        if(fast) fast = fast->next;
    } while(fast);
    
    prev->next = revList(slow);
    
    ListNode * p1 = A, * p2 = prev->next;
    while(p1 and p2){
        if(p1->val != p2->val) return 0;
        p1 = p1->next;
        p2 = p2->next;
    }
    return 1;
}
