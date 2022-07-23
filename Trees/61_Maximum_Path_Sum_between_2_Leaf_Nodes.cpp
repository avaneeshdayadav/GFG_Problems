// Problem Link : https://practice.geeksforgeeks.org/batch-problems/maximum-path-sum/0/?track=amazon-trees&batchId=192#
class Solution {
public:
    int maxPathSum(Node* root)
    {
        // code here 
        int maxPathSumTillNow = INT_MIN;

        int val = helper(root, maxPathSumTillNow);
               
          //--- for test case ---
           //         7                
          //        /    \              
            //    Null   -3           
          // value of maxPathSumTillNow will be INT_MIN but the answer is 4 , which is returned by the
          // function maxPathSumUtil().
       
          if(root->left && root->right)
                return maxPathSumTillNow;
          return max(maxPathSumTillNow, val);
    }
    
    int helper(Node *root, int &maxPathSumTillNow)
    {
        if(root == NULL)
            return 0;
        
        if(!root->left && !root->right)
            return root->data;
        
        int leftPathSum = helper(root->left,maxPathSumTillNow);
        int rightPathSum = helper(root->right,maxPathSumTillNow);
        
        // Update maxPathSumTillNow only if both child of root present.
        if(root->left && root->right)
        {
            maxPathSumTillNow = max(maxPathSumTillNow, leftPathSum+rightPathSum+root->data);
            return root->data + max(leftPathSum,rightPathSum);
        }
        
        return (!root->left)?rightPathSum+root->data:leftPathSum+root->data;
            
    }
};
