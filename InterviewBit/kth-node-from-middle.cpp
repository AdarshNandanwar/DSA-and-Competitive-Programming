// https://www.interviewbit.com/problems/kth-node-from-middle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
int getLen(ListNode * A){
    int res = 0;
    while(A){
        res++;
        A = A->next;
    }
    return res;
}
 
int Solution::solve(ListNode* A, int B) {
    int n = getLen(A);
    int mid = n/2+1;
    if(mid-B<=0) return -1;
    for(int i = 0; i<mid-B-1; i++) A = A->next;
    return A->val;
}
