// https://www.interviewbit.com/problems/even-reverse/

// Method (O(n) time, O(n) space):

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverseList(ListNode * head){
    ListNode * cur = head, * prev = NULL, * temp;
    while(cur){
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}
 
ListNode* Solution::solve(ListNode* A) {
    if(!A) return A;
    
    ListNode dummyOdd(0), dummyEven(0), * pt1, * pt2;
    ListNode * cur = A;
    int n = 0;
    while(cur){
        n++;
        cur = cur->next;
    }
    
    // odd
    pt1 = &dummyOdd;
    cur = A;
    while(cur){
        pt1->next = new ListNode(cur->val);
        pt1 = pt1->next;
        cur = cur->next;
        if(cur) cur = cur->next;
    }
    
    // even
    A = reverseList(A);
    cur = (n%2) ? A->next : A;
    pt2 = &dummyEven;
    while(cur){
        pt2->next = new ListNode(cur->val);
        pt2 = pt2->next;
        cur = cur->next;
        if(cur) cur = cur->next;
    }
    
    ListNode dummyRes(0);
    cur = &dummyRes;
    pt1 = dummyOdd.next, pt2 = dummyEven.next;
    while(pt1 or pt2){
        cur->next = pt1;
        pt1 = pt1->next;
        cur = cur->next;
        if(pt2){
            cur->next = pt2;
            pt2 = pt2->next;
            cur = cur->next;
        }
    }
    return dummyRes.next;
}
