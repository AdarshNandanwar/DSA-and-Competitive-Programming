// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

// Method 1 (Dummy Node, O(n^2) time, O(1) space):

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
    // {Head of list after removing first x nodes that sum to 0, Prefix with 0 sum found?}
    pair<ListNode*, bool> getNextNodeAfterZeroSum(ListNode* head, int curSum){
        if(head == nullptr){
            return {nullptr, false};
        }
        curSum += head->val;
        if(curSum == 0){
            return {head->next, true};
        }
        return getNextNodeAfterZeroSum(head->next, curSum);
    }    
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy;
        dummy.next = head;
        ListNode* cur = &dummy;
        while(cur->next){
            pair<ListNode*, bool> nextNodeAfterZeroSum = getNextNodeAfterZeroSum(cur->next, 0);
            if(nextNodeAfterZeroSum.second){
                cur->next = nextNodeAfterZeroSum.first;
            } else {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};