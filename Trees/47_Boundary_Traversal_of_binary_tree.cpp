
// Problem Link : https://practice.geeksforgeeks.org/batch-problems/boundary-traversal-of-binary-tree/0/?track=amazon-trees&batchId=192#
class Solution {
public:
    vector<int> ans;
    vector <int> boundary(Node *root)
    {
        //Your code here
        
        if(root == NULL)
        return ans;
        
        // Print root node first as we don't want to print it twice while printing left and right borders seperately.
        ans.push_back(root->data);
        
        // Go to print only left boundary in top to bottom manner.
        printLeft(root->left);
        
        
        // Print leaves of left and right subtee seperately bcoz root already printed.
        printLeaves(root->left);
        printLeaves(root->right);
        

        // Go to print only right boundary in bottom to up manner.
        printRight(root->right);
        
        return ans;
    }
    
    void printLeft(Node *root)
    {
        if(root == NULL)
            return ;
        
        // If left child present then just print root data and go left else print root data and go right.
        if(root->left)
        {
            ans.push_back(root->data);
            printLeft(root->left);
        }
        else if(root->right)
        {
            ans.push_back(root->data);
            printLeft(root->right);
        }
    }
    
    void printRight(Node *root)
    {
        if(root == NULL)
            return ;
        
        // If right child present then just print root data and go right else print root data and go left.
        if(root->right)
        {
            printRight(root->right);
            ans.push_back(root->data);
        }
        else if(root->left)
        {
            printRight(root->left);
            ans.push_back(root->data);
        }
        
        // Do nothing if leaf node. As we will print it seperately.
    }
    
    void printLeaves(Node *root)
    {
        if(root == NULL)
            return ;
        
        // Only print if leaf node else ignore and check left and right subtree.
        if(!root->left && !root->right)
            ans.push_back(root->data);

        printLeaves(root->left);
        printLeaves(root->right);
    }
};

