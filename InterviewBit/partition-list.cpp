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
    ListNode * p1 = &dummy, * p2 = &dummy, * temp = NULL;
    while(p2->next) {
        if(p2->next->val < B){
            if(p1!=p2){
                temp = p2->next;
                p2->next = p2->next->next;
                temp->next = p1->next;
                p1 = p1->next = temp;
            } else {
                p1 = p2 = p2->next;
            }
        } else {
            p2 = p2->next;
        }
    }
    return dummy.next;
}
