// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    
    Node * prev = NULL;
    
    Node* flatten(Node* head) {
        if(!head) return NULL;
        head->prev = prev;
        if(prev) prev->next = head;
        prev = head;
        Node * next = head->next;
        if(head->child) {
            flatten(head->child);
            head->next = head->child;
            head->child = NULL;
        }
        flatten(next);
        return head;
    }
};