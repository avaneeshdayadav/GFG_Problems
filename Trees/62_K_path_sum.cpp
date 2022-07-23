// Problem Link : https://practice.geeksforgeeks.org/batch-problems/k-sum-paths/0/?track=amazon-trees&batchId=192#
class Solution{
  public:
    int sumK(Node *root,int k)
    {
        // code here
        int cnt = 0;
        vector<int> path;
        printKPathUtil(root,path,k,cnt);
        return cnt;
    }
    
    void printKPathUtil(Node* root, vector<int>& path, int k, int &cnt)
    {
        // empty node
        if (!root)
            return;
      
        // add current node to the path
        path.push_back(root->data);
      
        // check if there's any k sum path
        // in the left sub-tree.
        printKPathUtil(root->left, path, k, cnt);
      
        // check if there's any k sum path
        // in the right sub-tree.
        printKPathUtil(root->right, path, k, cnt);
      
        // check if there's any k sum path that
        // terminates at this node
        // Traverse the entire path as
        // there can be negative elements too
        int f = 0;
        
        // Trverse path array from end towards start.
        for (int j = path.size() - 1; j >= 0; j--) {
            f += path[j];
      
            // If path sum is k, print the path
            if (f == k)
                cnt++;
        }
      
        // Remove the current element from the path
        path.pop_back();
    }
};

