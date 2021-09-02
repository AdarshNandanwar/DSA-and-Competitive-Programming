// https://www.interviewbit.com/problems/reorder-list/

// Method 1 (Recursion, O(n)):

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode * helper(ListNode * A, int len){
    if(len == 1){
        auto ret = A->next;
        A->next = NULL;
        return ret;
    }
    if(len == 2){
        auto ret = A->next->next;
        A->next->next = NULL;
        return ret;
    }
    auto tail = helper(A->next, len-2);
    auto ret = tail->next;
    tail->next = A->next;
    A->next = tail;
    return ret;
} 
 
ListNode* Solution::reorderList(ListNode* A) {
    if(!A) return A;
    int len = 0;
    auto p1 = A;
    while(p1){
        len++;
        p1 = p1->next;
    }
    helper(A, len);
    return A;
}

// Method 2 (Split, Reverse, Merge, O(n));

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode * reverse(ListNode * B){
    ListNode * prev = NULL;
    while(B){
        auto temp = B->next;
        B->next = prev;
        prev = B;
        B = temp;
    }
    return prev;
} 
 
ListNode* Solution::reorderList(ListNode* A) {
    if(!A or !A->next) return A;
    ListNode * slow = A, * fast = A;
    while(fast->next and fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode * B = slow->next;
    slow->next = NULL;
    
    B = reverse(B);
    
    auto p1 = A;
    while(A and B){
        auto temp = A->next;
        A->next = B;
        B = B->next;
        A->next->next = temp;
        A = A->next->next;
    }
    
    return p1;
}
