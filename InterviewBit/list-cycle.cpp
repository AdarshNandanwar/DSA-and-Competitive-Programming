// https://www.interviewbit.com/problems/list-cycle/

// Method 1 (Floyd's slow fast pointer):

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(!A) return A;

    ListNode * slow = A, * fast = A;
    
    do{
        slow = slow->next;
        fast = fast->next;
        if(fast) fast = fast->next;
    } while(fast and slow != fast);
    
    if(fast == NULL) return NULL;
    
    slow = A;
    
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
