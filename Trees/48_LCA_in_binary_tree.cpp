// Problem Link : https://practice.geeksforgeeks.org/batch-problems/lowest-common-ancestor-in-a-binary-tree/0/?track=amazon-trees&batchId=192
class Solution
{
    public:
    // In O(n) time & O(1) space.
    Node* lca(Node* root ,int a ,int b )
    {
      if(root == NULL)
        return NULL;
        
        if(root->data == a || root->data == b)
        return root;
        
        Node *l = lca(root->left, a, b);
        Node *r = lca(root->right, a,b);
        
        if(l == NULL)
        return r;
        
        if(r == NULL)
        return l;
        
        return root;
       
    }
    
    // In O(N) time and O(N) Space.
        // Node* lca(Node* root ,int n1 ,int n2 )
        // {
        //   //Your code here
        //   vector<Node*> path1, path2;
     
        //     // Find paths from root to n1 and root to n1. If either n1 or n2
        //     // is not present, return -1
        //     if ( !findPath(root, path1, n1) || !findPath(root, path2, n2))
        //           return NULL;
         
        //     /* Compare the paths to get the first different value */
        //     int i;
        //     for (i = 0; i < path1.size() && i < path2.size() ; i++)
        //         if (path1[i]->data != path2[i]->data)
        //             break;
        //     return path1[i-1];
           
        // }
        
        // bool findPath(Node *root, vector<Node*> &path,int k)
        // {
        //     if (root == NULL) return false;
     
        //     // Store this node in path vector. The node will be removed if
        //     // not in path from root to k
        //     path.push_back(root);
         
        //     // See if the k is same as root's key
        //     if (root->data == k)
        //         return true;
         
        //     // Check if k is found in left or right sub-tree
        //     if ( (root->left && findPath(root->left, path, k)) ||
        //          (root->right && findPath(root->right, path, k)) )
        //         return true;
         
        //     // If not present in subtree rooted with root, remove root from
        //     // path[] and return false
        //     path.pop_back();
        //     return false;
        // }

};

