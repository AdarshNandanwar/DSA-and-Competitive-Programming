// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

// Method 1 (Global variable prev, O(n)):

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

// Method 2 (Recursive function returning last node, O(n)):

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
    
    Node * flattenChild(Node * head, Node * prev){
        if(!head) return prev;
        head->prev = prev;
        if(head->child){
            Node * temp = head->next;
            head->next = head->child;
            head->child = NULL;
            Node * last = flattenChild(head->next, head);
            last->next = temp;
            return flattenChild(temp, last);
        } else {
            return flattenChild(head->next, head);
        }
    }
    
    Node* flatten(Node* head) {
        flattenChild(head, NULL);
        return head;
    }
};