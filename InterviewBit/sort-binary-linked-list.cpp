// https://www.interviewbit.com/problems/sort-binary-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    if(!A) return A;
    ListNode dummy(0), newDummy(0);
    dummy.next = A;
    ListNode * p1 = &dummy, * p2 = &newDummy;
    while(p2->next) p2 = p2->next;
    while(p1->next){
        if(p1->next->val){
            p2 = p2->next = p1->next;
            p1->next = p1->next->next;
            p2->next = NULL;
        } else {
            p1 = p1->next;
        }
    }
    p1->next = newDummy.next;
    return dummy.next;
}
