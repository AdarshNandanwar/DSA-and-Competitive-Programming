// https://www.interviewbit.com/problems/reverse-link-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
pair<ListNode *, ListNode *> rev(ListNode* A, int l){
    ListNode * prev = NULL;
    for(int i = 0; i<l; i++){
        auto temp = A->next;
        A->next = prev;
        prev = A;
        A = temp;
    }
    return {prev, A};
}
 
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(!A or B == C) return A;
    ListNode dummy(0);
    dummy.next = A;
    auto cur = &dummy;
    for(int i = 0; i<B-1; i++){
        cur = cur->next;
    }
    auto temp = cur->next;
    auto res = rev(cur->next, C-B+1);
    cur->next = res.first;
    temp->next = res.second;
    return dummy.next;
}
