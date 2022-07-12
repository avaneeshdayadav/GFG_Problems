// Problem Link : https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/0/?track=amazon-bst&batchId=192#
class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
    int minDiff(Node *root, int K)
    {
        //Your code here
        int  diff = INT_MAX;
        
        closestDist(root, diff, K);
        return diff;
    }
    
    void closestDist(Node *root, int &diff, int K)
    {
        if(root == NULL)
            return;
        
        if(root->data == K)
        {
            diff = 0;
            return;
        }
        else if(root->data > K)
        {
            diff = min(diff,abs(root->data - K));
            closestDist(root->left, diff, K);
        }
        else
        {
            diff = min(diff,abs(root->data - K));
            closestDist(root->right, diff, K);
        }
    }
};


