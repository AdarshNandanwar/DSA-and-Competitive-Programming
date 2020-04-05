int height(node * root){
    if(root == NULL){
        return -1;
    }
    return root->ht;
}

node * rotateLL(node * root){
    node * left = root->left;
    root->left = left->right;
    left->right = root;
    return left;
}

node * rotateRR(node * root){
    node * right = root->right;
    root->right = right->left;
    right->left = root;
    return right;
}

node * rotateLR(node * root){
    node * left = root->left;
    node * leftright = root->left->right;
    left->right = leftright->left;
    root->left = leftright->right;
    leftright->left = left;
    leftright->right = root;
    return leftright;
}

node * rotateRL(node * root){
    node * right = root->right;
    node * rightleft = root->right->left;
    root->right = rightleft->left;
    right->left = rightleft->right;
    rightleft->left = root;
    rightleft->right = right;
    return rightleft;
}

node * insert(node * root, int val){
    if(root == NULL){
        root = new node();
        root->val = val;
        root->left = NULL;
        root->right = NULL;
        root->ht = 0;
        return root;
    }
    if(val < root->val){
        root->left = insert(root->left, val);
    } else if(root->val < val){
        root->right = insert(root->right, val);
    } else {
        return root;
    }
    
    if(height(root->left)-height(root->right) > 1 && val < root->left->val){
        root = rotateLL(root);
    }
    else if(height(root->left)-height(root->right) > 1 && val > root->left->val){
        root = rotateLR(root);
    }
    else if(height(root->left)-height(root->right) < -1 && val < root->left->val){
        root = rotateRL(root);
    }
    else if(height(root->left)-height(root->right) < -1 && val > root->left->val){
        root = rotateRR(root);
    }

    root->ht = 1+max(height(root->left), height(root->right));

    return root;
}