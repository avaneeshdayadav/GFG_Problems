class Solution{
  public:
    /*You are required to complete below method */
    
    vector<int> btWithKleaves(Node *ptr, int k)
    { 
        //your code here.
        
        vector<int> ans;
        cntLeaves(ptr, k, ans);
        
        if(ans.size() == 0)
            return {-1};
        return ans;
    }
    
    int cntLeaves(Node *root, int &k, vector<int> &ans)
    {
        if(root == NULL)
            return 0;
        
        if(!root->left && !root->right)
            return 1;
        
        int leftLeafCnt = cntLeaves(root->left, k, ans);
        int rightLeafCnt = cntLeaves(root->right, k, ans);
        
        
        if(leftLeafCnt + rightLeafCnt == k)
            ans.push_back(root->data);
            
        return leftLeafCnt + rightLeafCnt;
        
    }

};
