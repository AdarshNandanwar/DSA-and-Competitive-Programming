// https://www.interviewbit.com/problems/unique-binary-search-trees/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<TreeNode*> helper(int st, int end){
    if(st > end) return vector<TreeNode*>(1, NULL);
    vector<TreeNode*> res;
    // i is the root val
    for(int i = st; i<=end; i++){
        auto left = helper(st, i-1);
        auto right = helper(i+1, end);
        for(auto l:left){
            for(auto r:right){
                TreeNode * root = new TreeNode(i);
                root->left = l;
                root->right = r;
                res.push_back(root);
            }
        }
    }
    return res;
}

vector<TreeNode*> Solution::generateTrees(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    return helper(1, A);
}
