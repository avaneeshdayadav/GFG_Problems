// Problem Link : https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/0/?track=amazon-bst&batchId=192#


// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    int kthLargest(Node *root, int K)
    {
        //Your code here
        vector<int> arr;
        revInorder(root,arr,K);
        return arr[K-1];
        
    }
    
    void revInorder(Node *root, vector<int> &arr, int K)
    {
        if(root == NULL)
            return;
        
        revInorder(root->right,arr,K);
        
        arr.push_back(root->data);
        if(arr.size() == K)
            return;
            
        revInorder(root->left, arr,K);
    }
};

