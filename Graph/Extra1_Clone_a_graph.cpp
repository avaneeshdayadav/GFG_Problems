// Problem Link : https://leetcode.com/problems/clone-graph/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        unordered_map<Node*,Node*> mp;
        if(node == NULL)
            return NULL;

        
        Node *firstNode = new Node(node->val,{});
        mp[node] = firstNode;
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty())
        {
            Node *frontNode = q.front();
            q.pop();

            for( Node *adj : frontNode->neighbors)
            {
                if(mp.find(adj) == mp.end())
                {
                    mp[adj] = new Node(adj->val,{});
                    q.push(adj);
                }
                mp[frontNode]->neighbors.push_back(mp[adj]);
            }
        }
        return mp[node];
    }
    
};
