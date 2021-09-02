// https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int rev_len = right-left+1;
        left--;
        ListNode dummy(0);
        dummy.next = head;
        ListNode * cur = &dummy, * prev = NULL;
        while(left--) cur = cur->next;
        ListNode * rev_head = cur->next;
        while(rev_len--){
            auto temp = rev_head->next;
            rev_head->next = prev;
            prev = rev_head;
            rev_head = temp;
        }
        cur->next->next = rev_head;
        cur->next = prev;
        return dummy.next;
    }
};