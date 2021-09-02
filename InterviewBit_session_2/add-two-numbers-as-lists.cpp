// https://www.interviewbit.com/problems/add-two-numbers-as-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode dummy(0);
    auto cur = &dummy;
    int carry = 0, sum;
    while(A and B){
        sum = carry+A->val+B->val;
        carry = sum/10;
        cur->next = new ListNode(sum%10);
        cur = cur->next;
        A = A->next;
        B = B->next;
    }
    if(B) swap(A, B);
    while(A){
        sum = carry+A->val;
        carry = sum/10;
        cur->next = new ListNode(sum%10);
        cur = cur->next;
        A = A->next;
    }
    if(carry){
        sum = carry;
        cur->next = new ListNode(sum%10);
        cur = cur->next;
    }
    return dummy.next;
}
