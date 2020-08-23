// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/

// Method 1 (Dummy, O(n) time, O(1) space):

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode dummy(0);
    dummy.next = A;
    ListNode * cur = &dummy;
    while(cur->next){
        int v = cur->next->val;
        if(cur->next->next and cur->next->next->val == v){
            while(cur->next and cur->next->val == v) cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }
    return dummy.next;
}

// Mehtod 2 (O(n) time, O(n) space):

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A == NULL) return NULL;
    ListNode * cur = A, * res = NULL, *resCur;
    while(cur){
        int v = cur->val;
        if(cur->next and cur->next->val == cur->val){
            while(cur and cur->val == v) cur = cur->next;
        } else {
            if(res){
                resCur->next = new ListNode(v);
                resCur = resCur->next;
            } else {
                res = resCur = new ListNode(v);
            }
            cur = cur->next;
        }
    }
    return res;
}
