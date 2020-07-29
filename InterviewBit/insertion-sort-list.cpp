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
    
    if(A == NULL) return NULL;
    
    ListNode * head = A, * i = A, * j = A, * iPrev = head, * jPrev;
    
    for(i = head->next; i; i = i->next){
        jPrev = NULL;
        for(j = head; j!=i; j = j->next){
            if(j->val > i->val){
                if(jPrev){
                    iPrev->next = i->next;
                    jPrev->next = i;
                    i->next = j;
                } else {
                    iPrev->next = i->next;
                    i->next = head;
                    head = i;
                }
                break;
            }
            jPrev = j;
        }
        iPrev = i;
    }
    return head;
}
