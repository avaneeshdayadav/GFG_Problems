// Problem Link ; https://practice.geeksforgeeks.org/batch-problems/vertical-sum/0/?track=amazon-trees&batchId=192#
class Solution{
  public:
    vector <int> verticalSum(Node *root) {
        /// {hor_dist_from_root, node val}
        vector<int> ans;
        
        
        // Queue Soln i.e BFS.
            // map<int,vector<int>> mp;

            // // {hor_dist_from_root, node}
            // queue<pair<int,Node *>> q;
            // q.push({0,root});
            
            // while(!q.empty())
            // {
            //     pair<int,Node*> f = q.front();
                
            //     mp[f.first].push_back(f.second->data);
                
            //     q.pop();
                
            //     // If travelling left decrease horizontol dist of left node by 1 from curr node & then push in queue.
            //     if(f.second->left)
            //         q.push({f.first - 1,f.second->left});
                
            //     // If travelling right increase horizontol dist of right node by 1 from curr node &  then push in queue.
            //     if(f.second->right)
            //         q.push({f.first + 1,f.second->right});
            // }
            
            // for(auto it : mp)
            // {
            //     int sum = 0;
            //     for(auto it2: it.second)
            //     {
            //         sum += it2;
            //     }
            //     ans.push_back(sum);
            // }
            
            // return ans;

        // Inorder trav soln.
        map < int, int> mp;
        verticalSumUtil(root,0,mp);
        for(auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
    
    void verticalSumUtil(Node *node, int hd, map<int, int> &Map)
    {
        // Base case
        if (node == NULL) return;
      
        // Recur for left subtree
        verticalSumUtil(node->left, hd-1, Map);
      
        // Add val of current node to
        // map entry of corresponding hd
        Map[hd] += node->data;
      
        // Recur for right subtree
        verticalSumUtil(node->right, hd+1, Map);
    }
};

