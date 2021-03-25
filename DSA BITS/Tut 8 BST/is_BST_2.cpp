/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
    bool check(Node * root, int st, int end){
        if(!root){
            return true;
        }
        if(root->data <= st || root->data >= end)
            return false;
        if(!check(root->left, st, root->data) || !check(root->right, root->data, end))
            return false;
        else
            return true;
    }
    bool checkBST(Node* root) {
        return check(root, -1, 10001);
    }