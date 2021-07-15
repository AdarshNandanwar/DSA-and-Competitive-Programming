// https://www.interviewbit.com/problems/insertion-sort-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    if(!A) return A;
    ListNode dummy(0);
    dummy.next = A;
    ListNode * p1 = A, * p2;
    while(p1->next){
        p2 = &dummy;
        while(p2 != p1 and p2->next->val <= p1->next->val) p2 = p2->next;
        if(p1 != p2){
            auto temp = p1->next;
            p1->next = p1->next->next;
            temp->next = p2->next;
            p2->next = temp;
        } else {
            p1 = p1->next;
        }
    }
    return dummy.next;
}
