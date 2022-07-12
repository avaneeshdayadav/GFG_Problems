// Problem Link : https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/0/?track=amazon-bst&batchId=192#

Node * findInorderSucc(Node *root)
{
    if(root == NULL)
        return NULL;
    
    if(root->left == NULL)
        return root;
    else
        findInorderSucc(root->left);
}


// Function to delete a node from BST.
Node *deleteNode(Node *root, int X) {
    // your code goes here
    
    if(root == NULL)
        return root;
    else if(root->data < X)
        root->right = deleteNode(root->right, X);
    else if(root->data > X)
        root->left = deleteNode(root->left, X);
    else // We found the node to be deleteed.
    {
        //If Leaf node.
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
            return root;
        }
        else if(root->left == NULL)
        {
            Node * temp = root->right;
            root = NULL;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            Node * temp = root->left;
            root = NULL;
            free(root);
            return temp;
        }
        else // If both child present.
        {
            Node *inorderSuccNode = findInorderSucc(root->right);
            root->data = inorderSuccNode->data;
            root->right = deleteNode(root->right, inorderSuccNode->data);
        }
        
    }
}

