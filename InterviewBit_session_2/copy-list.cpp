// https://www.interviewbit.com/problems/copy-list/

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    unordered_map<RandomListNode* , RandomListNode*> m;
    RandomListNode* cur = A;
    while(cur){
        if(!m.count(cur)) m[cur] = new RandomListNode(cur->label);
        cur = cur->next;
    }
    cur = A;
    while(cur){
        m[cur]->next = m[cur->next];
        m[cur]->random = m[cur->random];
        cur = cur->next;
    }
    return m[A];
}
