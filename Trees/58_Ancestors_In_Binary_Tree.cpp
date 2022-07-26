class Solution{
  public:
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target)
    {
         // Code here
         vector<int> ans;
         findTarget(root,target,root->data,ans);
         return ans;
         
    }
    
    bool findTarget(Node *root, int &target, int parent, vector<int> &ans)
    {
        if(root == NULL)
            return false;
        
        if(root->data == target)
            return true;
        
        bool leftSearch = findTarget(root->left, target, root->data, ans);
        bool rightSearch = findTarget(root->right, target, root->data, ans);
        
        if(leftSearch || rightSearch)
        {
            ans.push_back(root->data);
            return true;
        }
        
        return false;
    }
};

