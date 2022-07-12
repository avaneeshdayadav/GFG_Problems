// Problem Link : https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/0/?track=amazon-bst&batchId=192#
class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        // add code here.
        
        int cnt = 0, ans = -1;
        inorder(root, cnt, K, ans);
        
        if(cnt < K)
            return -1;
        return ans;
        
    }
    
    
    void inorder(Node *root, int &cnt, int &K, int &ans)
    {
        if(root == NULL)
            return;
        
        inorder(root->left, cnt, K, ans);
        
        cnt++;
        // Everytime cnt is less than k we update ans.
        if(cnt <= K)
            ans = root->data;
        
        inorder(root->right, cnt, K, ans);
    }
};

