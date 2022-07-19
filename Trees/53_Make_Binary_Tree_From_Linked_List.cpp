// Problem Link : https://practice.geeksforgeeks.org/batch-problems/make-binary-tree/0/?track=amazon-trees&batchId=192#

TreeNode* buildTree(Node *&LLptr)
{
    if(LLptr == NULL)
        return NULL;

    TreeNode *newNode = new TreeNode(LLptr->data);
    LLptr = LLptr->next;
    
    newNode->left = buildTree(LLptr);
    newNode->right = buildTree(LLptr);
    
    return newNode;

}

//Function to make binary tree from linked list.
void convert(Node *head, TreeNode *&root) {
    // Your code here
    root = buildTree(head);
    
}


