// https://www.interviewbit.com/problems/even-reverse/

// Method 1 (O(n) time, O(1) space):

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
    
    ListNode dummy(0), dummyEven(0);
    dummy.next = A;
    ListNode * cur1 = A, * cur2 = &dummyEven;
    
    // remove even nodes
    while(cur1 and cur1->next){
        cur2 = cur2->next = cur1->next;
        cur1 = cur1->next = cur1->next->next;
        cur2->next = NULL;
    }
    
    // reverse even nodes
    dummyEven.next = reverseList(dummyEven.next);
    
    // insert even nodes
    ListNode * temp;
    cur1 = dummy.next, cur2 = &dummyEven;
    while(cur2->next){
        temp = cur2->next->next;
        cur2->next->next = cur1->next;
        cur1->next = cur2->next;
        cur1 = cur1->next->next;
        cur2->next = temp;
    }
    
    return dummy.next;
}

// Method 2 (O(n) time, O(n) space):

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
