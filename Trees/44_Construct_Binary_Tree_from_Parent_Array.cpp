
// Problem Link : https://practice.geeksforgeeks.org/batch-problems/construct-binary-tree-from-parent-array/0/?track=amazon-trees&batchId=192#


class Solution{
  public:
    //Function to construct binary tree from parent array.
    Node *createTree(int parent[], int n)
    {
        unordered_map<int, Node*> mp;
        Node* root = NULL;
        
        // Make all nodes and store it in map or vector.
        for(int i=0; i<n; i++)
        {
            Node* newnode = new Node(i);
            mp[i] = newnode;
        }
          
        
        // Construct parent child links
        for(int i=0;i<n;i++)
        {
            if(parent[i] == -1)
            {
                root = mp[i];
            }
            else
            {
                int child = i, par = parent[i];
                
                if(mp[par]->left == NULL)
                    mp[par]->left = mp[child];
                else
                    mp[par]->right = mp[child];
            }
        }
        return root;
   }
};
