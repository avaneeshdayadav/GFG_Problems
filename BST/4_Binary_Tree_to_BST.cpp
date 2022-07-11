class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int> inorderTrav;
        
        inorder(root,inorderTrav);
        
        sort(inorderTrav.begin(), inorderTrav.end());
        
        int indx = 0;
        inorderPaste(root, inorderTrav, indx);
        
        return root;
        
    }
    
    void inorder(Node *root, vector<int> &inorderTrav)
    {
        if(!root)
            return;
            
        inorder(root->left, inorderTrav);
        inorderTrav.push_back(root->data);
        inorder(root->right, inorderTrav);
    }
    
    void inorderPaste(Node *root, vector<int> &inorderTrav, int &indx)
    {
        if(!root)
            return;
        
        inorderPaste(root->left, inorderTrav, indx);
        root->data = inorderTrav[indx];
        indx++;
        inorderPaste(root->right, inorderTrav, indx);
        
    }
};

