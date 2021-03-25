// https://www.interviewbit.com/problems/populate-next-right-pointers-tree/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    if(!A) return;
    TreeLinkNode * prev = NULL;
    queue<TreeLinkNode*> q;
    q.push(A);
    while(!q.empty()){
        prev = NULL;
        int sz = q.size();
        for(int i = 0; i<sz; i++){
            auto cur=  q.front();
            q.pop();
            cur->next = prev;
            prev = cur;
            if(cur->right) q.push(cur->right);
            if(cur->left) q.push(cur->left);
        }
    }
}
