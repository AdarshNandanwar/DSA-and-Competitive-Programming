// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

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
        cur = cur->next;
        while(cur->next and cur->next->val == cur->val) cur->next = cur->next->next;
    }
    return dummy.next;
}
