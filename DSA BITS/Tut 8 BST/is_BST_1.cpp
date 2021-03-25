/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
    void inOrder(Node * root, vector<int> & v){
        if(!root){
            return;
        }
        inOrder(root->left, v);
        v.push_back(root->data);
        inOrder(root->right, v);
    }
	bool checkBST(Node* root) {
		vector<int> v;
        inOrder(root, v);
        for(int i = 1; i < v.size(); i++){
            if(v[i] <= v[i-1])
                return false;
        }
        return true;
	}