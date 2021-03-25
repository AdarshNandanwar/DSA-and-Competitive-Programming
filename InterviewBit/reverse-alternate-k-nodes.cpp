// https://www.interviewbit.com/problems/reverse-alternate-k-nodes/

// Method 1 (Loop, O(n)):

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode * rev(ListNode* A, ListNode* prev, int B){
    ListNode * temp = NULL, * cur = A;
    while(B--){
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}
 
 
ListNode* Solution::solve(ListNode* A, int B) {
    ListNode * head = A, * cur = A, * st = NULL;
    ListNode dummy(0);
    ListNode * last = &dummy, * curLast = &dummy;
    int i;
    while(cur){
        st = cur;
        for(i = 0; i<B; i++){
            if(cur){
                curLast = cur;
                cur = cur->next;
            } 
            else break;
        }
        last->next = rev(st, cur, i);
        for(i = 0; i<B; i++){
            if(cur){
                curLast = cur;
                cur = cur->next;
            } 
            else break;
        }
        last = curLast;
    }
    return dummy.next;
}

// Method 2 (Recursion), O(n)):

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode * rev(ListNode* A, ListNode* prev, int B){
    ListNode * temp = NULL, * cur = A;
    while(B--){
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}
 
 
ListNode* Solution::solve(ListNode* A, int B) {
    if(A == NULL) return NULL;
    ListNode * head = A, * cur = A, * res = NULL, * prev = NULL;
    int i;
    for(i = 0; i<B; i++){
        if(cur) cur = cur->next;
        else break;
    }
    res = rev(A, cur, i);
    for(i = 0; i<B; i++){
        if(cur){
            prev = cur;
            cur = cur->next;
        } 
        else break;
    }
    if(prev) prev->next = solve(cur, B);
    return res;
}
