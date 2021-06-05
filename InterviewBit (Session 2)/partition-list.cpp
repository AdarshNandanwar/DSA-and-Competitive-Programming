// https://www.interviewbit.com/problems/partition-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode dummy(0);
    dummy.next = A;
    
    ListNode * h1 = &dummy, * h2 = &dummy;
    while(h2->next){
        if(h2->next->val < B){
            if(h1 == h2){
                h2 = h2->next;
                h1 = h1->next;
            } else {
                auto temp = h1->next;
                h1->next = h2->next;
                h2->next = h2->next->next;
                h1 = h1->next;
                h1->next = temp;
            }
        } else {
            h2 = h2->next;
        }
    }
    return dummy.next;
}
