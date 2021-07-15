// https://www.interviewbit.com/problems/intersection-of-linked-lists/

// Method 1 (Slow Fast Pointer):

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    if(!A or !B) return NULL;
    auto cur = A;
    while(cur->next){
        cur = cur->next;
    }
    cur->next = B;
    
    auto slow = A, fast = A;
    do{
        if(!fast or !fast->next) return NULL;
        fast = fast->next->next;
        slow = slow->next;
    }while(slow != fast);
    fast = A;
    while(slow != fast){
        fast = fast->next;
        slow = slow->next;
    }
    cur->next = NULL;
    return slow;
}

// Method 2 (calculate length):

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int la = 0, lb = 0;
    auto cur = A;
    while(cur){ 
        cur= cur->next;
        la++;
    }
    cur = B;
    while(cur){ 
        cur= cur->next;
        lb++;
    }
    while(la<lb){
        B = B->next;
        lb--;
    }
    while(la>lb){
        A = A->next;
        la--;
    }
    while(A and B and A != B){
        A = A->next;
        B = B->next;
    }
    return A;
}
