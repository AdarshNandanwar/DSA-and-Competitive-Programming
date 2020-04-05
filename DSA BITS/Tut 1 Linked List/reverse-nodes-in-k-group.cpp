struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* helper(ListNode* head, int k, int size) {
    if(size<k){
        return head;
    }
    ListNode * tail = head;
    for(int i = 0; i<k; i++){
        tail = tail->next;
    }
    ListNode * prev = helper(tail, k, size-k);
    ListNode* current = head, *temp;
    for(int i = 0; i<k; i++){
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    return prev;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    int size = 0;
    ListNode * curr = head;
    while(curr != NULL){
        size++;
        curr = curr->next;
    }
    return helper(head, k, size);
}