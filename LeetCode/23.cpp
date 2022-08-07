// https://leetcode.com/problems/merge-k-sorted-lists/

// Method 1 (Min Heap, O(nlogk)):

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
    class Cmp{
    public:
        bool operator()(const ListNode * a, const ListNode * b) const {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, Cmp> pq;
        for(auto & list:lists){
            if(list){
                pq.push(list);
            }
        }
        ListNode dummy;
        ListNode * head = &dummy;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            if(cur->next){
                pq.push(cur->next);
            }
            head->next = cur;
            head = head->next;
        }
        head->next = NULL;
        return dummy.next;
    }
};