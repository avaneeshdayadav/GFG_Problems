class Solution{
  public:
    /* The function should clone the passed tree and return 
       root of the cloned tree */
       
    map<Node*,Node*> mp;
    Node* cloneTree(Node* root)
    {
       fillMap(root);
       cloneLeftRight(root);
       setRandomPtr(root);
    //   preOrder(root);
       return mp[root];
    }
    
    void fillMap(Node *root)
    {
        if(root == NULL)
            return;
            
        if(mp.find(root) == mp.end())
        {
            mp[root] = new Node(root->data);
        }
        
        fillMap(root->left);
        fillMap(root->right);
    }
    
    void cloneLeftRight(Node *root)
    {
        if(root == NULL)
            return;
        
        if(root->left)
        mp[root]->left = mp[root->left];
        
        if(root->right)
        mp[root]->right = mp[root->right];
        
        cloneLeftRight(root->left);
        cloneLeftRight(root->right);
    }
    
    
    void setRandomPtr(Node *root)
    {
        if(root == NULL)
            return;
        
        if(root->random)
        mp[root]->random = mp[root->random];
        
        setRandomPtr(root->left);
        setRandomPtr(root->right);
    }
    
    
    // Just for checking cloned tree using traversal.
    void preOrder(Node *root)
    {
        if(root == NULL)
            return;
        
        cout<<root->data<<endl;
        preOrder(root->left);
        preOrder(root->right);
    }
};
