// Problem Link ; https://practice.geeksforgeeks.org/batch-problems/vertical-sum/0/?track=amazon-trees&batchId=192#
class Solution{
  public:
    vector <int> verticalSum(Node *root) {
        /// {hor_dist_from_root, node val}
        map<int,vector<int>> mp;
        vector<int> ans;
        
        // {hor_dist_from_root, node}
        queue<pair<int,Node *>> q;
        q.push({0,root});
        
        while(!q.empty())
        {
            pair<int,Node*> f = q.front();
            
            mp[f.first].push_back(f.second->data);
            
            q.pop();
            
            // If travelling left decrease horizontol dist of left node by 1 from curr node & then push in queue.
            if(f.second->left)
                q.push({f.first - 1,f.second->left});
            
            // If travelling right increase horizontol dist of right node by 1 from curr node &  then push in queue.
            if(f.second->right)
                q.push({f.first + 1,f.second->right});
        }
        
        for(auto it : mp)
        {
            int sum = 0;
            for(auto it2: it.second)
            {
                sum += it2;
            }
            ans.push_back(sum);
        }
        
        return ans;
        
    }
};

