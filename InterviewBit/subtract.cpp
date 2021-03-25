// https://www.interviewbit.com/problems/subtract/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::subtract(ListNode* A) {
    int n = 0;
    ListNode * head = A, * cur, * prev = NULL, * next = NULL, * lowerMid = NULL;
    
    // finding the lower midpoint i.e. (n-1)/2 - 1
    ListNode * slow = head, * fast = head;
    while(fast){
        lowerMid = slow;
        slow = slow->next;
        fast = fast->next;
        if(fast) fast = fast->next;
    }
    
    // reversing the second half
    prev = NULL;
    cur = lowerMid->next;
    while(cur){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    lowerMid->next = prev;
    
    // subtracting
    ListNode * p1 = head, * p2 = lowerMid->next;
    while(p2){
        p1->val = p2->val-p1->val;
        p1 = p1->next;
        p2 = p2->next;
    }
    
    // reversing the second half
    prev = NULL;
    cur = lowerMid->next;
    while(cur){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    lowerMid->next = prev;
    
    
    return head;
}
