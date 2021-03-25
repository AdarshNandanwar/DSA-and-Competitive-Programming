// https://leetcode.com/problems/merge-k-sorted-lists/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        ListNode * head = NULL, * curr = NULL;
        int n = lists.size(), min_index = -1;
        while(true){
            min_index = -1;
            for(int i = 0; i<n; i++){
                if(lists[i] == NULL) continue;
                if(min_index == -1 || lists[min_index]->val > lists[i]->val){
                    min_index = i;
                }
            }
            if(min_index == -1){
                break;
            }
            if(head == NULL){
                head = lists[min_index];
                curr = head;
            } else {
                curr->next = lists[min_index];
                curr = curr->next;
            }
            lists[min_index] = lists[min_index]->next;
        }
        if(curr)
            curr->next = NULL;
        return head;
    }
};