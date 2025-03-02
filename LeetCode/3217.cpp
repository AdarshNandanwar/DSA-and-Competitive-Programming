// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/

// Method 1 (Loops, Dummy Node, O(n)):

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numsSet(nums.begin(), nums.end());

        ListNode dummy;
        dummy.next = head;
        ListNode * cur = &dummy;
        while(cur->next){
            if(numsSet.count(cur->next->val)){
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }

        return dummy.next;
    }
};
