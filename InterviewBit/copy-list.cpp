// https://www.interviewbit.com/problems/copy-list/

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

unordered_map<RandomListNode*, RandomListNode*> m;
 
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    if(!A) return A;
    if(m.count(A)) return m[A];
    RandomListNode * head = m[A] = new RandomListNode(A->label);
    head->next = copyRandomList(A->next);
    head->random = copyRandomList(A->random);
    return head;
}
