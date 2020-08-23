// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

// Method 1 (Dummy, O(n) time, O(1) space):

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
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
};