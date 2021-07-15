// https://www.interviewbit.com/problems/palindrome-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

pair<ListNode*, bool> helper(ListNode* A, int len){
    if(len == 1) return {A->next, 1};
    if(len == 2) return {A->next->next, A->val == A->next->val};
    
    auto h = helper(A->next, len-2);
    return {h.first->next, h.second and (A->val == h.first->val)};
}
 
int Solution::lPalin(ListNode* A) {
    if(!A) return 1;
    int len = 0;
    auto cur = A;
    while(cur){
        len++;
        cur = cur->next;
    }
    return helper(A, len).second;
}
