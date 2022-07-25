class Solution{
  public:
    /* Function to print nodes of extreme corners
    of each level in alternate order */
    vector<int> ExtremeNodes(Node* root)
    {
        // Your code here
        queue<Node*> q;
        vector<int> ans;
        // flag = 1 means print leftmost else rightmost.
        bool flag = 0;
        
        q.push(root);
        while(!q.empty())
        {
            int qSize = q.size();
            Node *prev;
         
            for(int i = 0;i < qSize;i++)
            {
                Node *f = q.front();
                q.pop();
                
                if(flag == 1 && i == 0)
                    ans.push_back(f->data);
                else if(flag == 0 && i == qSize-1)
                    ans.push_back(f->data);
                    
                if(f->left)
                    q.push(f->left);
                
                if(f->right)
                    q.push(f->right);
            }
            // Invert flag after every lvl.
            flag = !flag;
        }
        
        return ans;
    }
};

