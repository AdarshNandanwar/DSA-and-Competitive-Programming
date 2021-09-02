// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(!A) return A;
    ListNode dummy(0);
    dummy.next = A;
    auto p = &dummy;
    while(p->next and p->next->next){
        if(p->next->val == p->next->next->val){
            int val = p->next->val;
            while(p->next and p->next->val == val) p->next = p->next->next;
        } else {
            p = p->next;
        }
    }
    return dummy.next;
}
