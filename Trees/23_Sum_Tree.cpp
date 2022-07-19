// Problem Link : https://practice.geeksforgeeks.org/batch-problems/sum-tree/0/?track=amazon-trees&batchId=192#

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    bool isSumTree(Node* root)
    {
        // Your code here
        
        if(helper(root) == -1)
        return false;
        
        return true;
            
    }
    
    int helper(Node *root)
    {
        if(root == NULL)
            return 0;
        
        if(!root->left && !root->right)
            return root->data;
        
        int leftSum = helper(root->left);
        int rightSum = helper(root->right);
        
        if(leftSum == -1 || rightSum == -1 || (leftSum + rightSum) != root->data)
            return -1;
        
        return leftSum + rightSum + root->data;
        
    }
};

