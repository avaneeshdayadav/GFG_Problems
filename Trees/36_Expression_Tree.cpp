// Problem Link : https://practice.geeksforgeeks.org/batch-problems/expression-tree/0/?track=amazon-trees&batchId=192#
class Solution{
  public:
    /*You are required to complete below method */
    int evalTree(node* root){
        
        // Your code here
        if(!root->left && !root->right)
            return stoi(root->data);
        
        int leftEval = evalTree(root->left);
        int rightEval = evalTree(root->right);
        
        if(root->data == "*")
            return leftEval * rightEval;
        
        else if(root->data == "+")
            return leftEval + rightEval;
            
        else if(root->data == "-")
            return leftEval - rightEval;
            
        else
            return leftEval / rightEval;

        
    }
};

