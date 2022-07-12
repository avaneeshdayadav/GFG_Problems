// Problem Link : https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/0/?track=amazon-bst&batchId=192#
class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node *ans = NULL;
        bool found = false;
        inorder(root, x->data, ans, found);
        // cout<<ans->data<<endl;
        return ans;
    }
    
    void inorder(Node *root, int &xData , Node* &ans, bool &found)
    {
        if(root == NULL || found == true)
            return;
            
        inorder(root->left,xData,ans,found);
        
        if(root->data > xData && found == false)
        {
            found = true;
            ans = root;
        }
        
        inorder(root->right,xData,ans,found);
    }
};

