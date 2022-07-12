// Problem Link : https://practice.geeksforgeeks.org/problems/add-all-greater-values-to-every-node-in-a-bst/0/?track=amazon-bst&batchId=192#

void inorderPaste(Node *root, int &sum)
{
    if(root == NULL)
        return;
    
    inorderPaste(root->right, sum);
    
    root->data = root->data + sum;
    sum = root->data;
    
    inorderPaste(root->left, sum);
}


Node* modify(Node *root)
{
    int sum = 0;
    inorderPaste(root, sum);
    
    return root;
}


