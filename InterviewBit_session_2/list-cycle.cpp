// https://www.interviewbit.com/problems/list-cycle/

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
    
    auto slow = A, fast = A;
    do{
        if(!fast or !fast->next) return NULL;
        fast = fast->next->next;
        slow = slow->next;
    }while(slow != fast);
    fast = A;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
