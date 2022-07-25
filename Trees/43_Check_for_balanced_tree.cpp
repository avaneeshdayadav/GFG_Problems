class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(root == NULL)
            return true;
        
        if(height(root) < 0)
            return false;
        return true;
    }
    
    int height(Node *root)
    {
        if(root == NULL)
            return 0;
        
        int leftHt = height(root->left);
        int rightHt = height(root->right);
        
        if(leftHt == -1 || rightHt == -1)
            return -1;
        
        if(abs(leftHt-rightHt)>1)
            return -1;
            
        return max(leftHt,rightHt) + 1;
        
    }
};
