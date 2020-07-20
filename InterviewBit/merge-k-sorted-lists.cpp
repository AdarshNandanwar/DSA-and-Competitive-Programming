// https://www.interviewbit.com/problems/merge-k-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
struct Cmp{
    bool operator()(ListNode * a, ListNode * b){
        return a->val > b->val;
    }
};
 
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
    priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;
    for(auto i:A){
        if(i) pq.push(i);
    }
    ListNode * res = NULL, * head = NULL;
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(res){
            res->next = cur;
            res = res->next;
        } else {
            res = cur;
            head = res;
        }
        cur = cur->next;
        if(cur) pq.push(cur);
    }
    
    return head;
    
}
