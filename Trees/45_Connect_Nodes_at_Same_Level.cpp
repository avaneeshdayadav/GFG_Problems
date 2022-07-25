class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       // Your Code Here
       queue<Node*> q;
       q.push(root);
       while(!q.empty())
       {
           int qSize = q.size();
           Node *prev;
         
            for(int i = 0;i < qSize;i++)
            {
                Node *f = q.front();
                q.pop();
                
                if(f->left)
                    q.push(f->left);
                
                if(f->right)
                    q.push(f->right);
                
                if(i == 0)
                   prev = f;
                else
                {
                   prev->nextRight = f;
                   prev = f;
                }
                
                f->nextRight = NULL;
            }
       }
    } 
      
};

