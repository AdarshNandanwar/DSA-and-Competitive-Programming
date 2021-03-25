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
    int carry = 0, temp;
    ListNode * head = NULL, * cur = NULL;
    
    while(A and B){
        temp = A->val+B->val+carry;
        if(head){
            cur->next = new ListNode(temp%10);
            cur = cur->next;
        } else {
            head = cur = new ListNode(temp%10);
        }
        carry = temp/10;
        A = A->next;
        B = B->next;
    }
    while(A){
        temp = A->val+carry;
        if(head){
            cur->next = new ListNode(temp%10);
            cur = cur->next;
        } else {
            head = cur = new ListNode(temp%10);
        }
        carry = temp/10;
        A = A->next;
    }
    while(B){
        temp = B->val+carry;
        if(head){
            cur->next = new ListNode(temp%10);
            cur = cur->next;
        } else {
            head = cur = new ListNode(temp%10);
        }
        carry = temp/10;
        B = B->next;
    }
    if(carry){
        temp = carry;
        if(head){
            cur->next = new ListNode(temp%10);
            cur = cur->next;
        } else {
            head = cur = new ListNode(temp%10);
        }
        carry = temp/10;
    }
    return head;
}
