// https://leetcode.com/problems/copy-list-with-random-pointer/

// Method 1 (Hashing, O(n)):

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> m;
    Node* copyRandomList(Node* A) {
        if(!A) return A;
        if(m.count(A)) return m[A];
        Node * head = m[A] = new Node(A->val);
        head->next = copyRandomList(A->next);
        head->random = copyRandomList(A->random);
        return head;
    }
};

// Method 2 (Optimised code):

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        unordered_map<Node *, Node *> m;
        
        Node * curr = head, * currNew;
        Node * dummy = new Node(-1);
        
        currNew = dummy;
        
        while(curr){
            currNew->next = new Node(curr->val);
            m[curr] = currNew->next;
            curr = curr->next;
            currNew = currNew->next;
        }
        
        currNew = dummy->next;
        curr = head;
        
        while(curr){
            currNew->random = m[curr->random];
            curr = curr->next;
            currNew = currNew->next;
        }
        
        return dummy->next;
    }
};

// Method 3 (My code):

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        unordered_map<Node *, int> pos;
        unordered_map<int, Node *> loc;
        Node * start = new Node(head->val);
        Node * it1 = head->next, * it2 = start;
        pos[head] = 0;
        loc[0] = start;
        int index = 1;
        while(it1 != NULL){
            pos[it1] = index;
            Node * n = new Node(it1->val);
            it2->next = n;
            it1 = it1->next;
            it2 = it2->next;
            loc[index] = it2;
            index++;
        }
        
        it1 = head, it2 = start;
        while(it1 != NULL){
            if(it1->random == NULL){
                it2->random = NULL;
            } else {
                it2->random = loc[pos[it1->random]];
            }
            it1 = it1->next;
            it2 = it2->next;
        }
        return start;
    }
};