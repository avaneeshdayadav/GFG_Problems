void printCorner(Node *root)
{

    queue<Node*> q;

    q.push(root);
    while(!q.empty())
    {
        int qSize = q.size();

        for(int i = 0;i < qSize;i++)
        {
            Node *f = q.front();
            q.pop();
            
            if(i==0 || i==qSize-1)
                cout<<f->data<<" ";
            
            
            if(f->left)
                q.push(f->left);
            
            if(f->right)
                q.push(f->right);
        }
    }
    
}
