// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Prim's algo
        
        // visited Array, minWt Array, Parent Arr
        vector<int> vis(V,0), minWt(V,INT_MAX), parent(V,-1);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        
        int totalCost = 0;
        minWt[0] = 0;
        minHeap.push({0,0});
        
        while(!minHeap.empty())
        {
            pair<int,int> top = minHeap.top();
            
            int currWt = top.first;
            int currNode = top.second;
            minHeap.pop();
            
            for(auto it : adj[currNode])
            {
                // If adj node already visited then we do nothing.
                if(!vis[it[0]])
                {
                    int adjNodeWt = it[1];
                    int adjNodeName = it[0];
                    
                    // If min wt of this adj node till now is > than wt from this curr node then update min wt & it's parent & push in heap.
                    if(minWt[adjNodeName] > adjNodeWt)
                    {
                        parent[adjNodeName] = currNode;
                        minWt[adjNodeName] = adjNodeWt;
                        minHeap.push({minWt[adjNodeName], adjNodeName});
                        
                    }
                }
            }
            // Not marking visited while pushing in heap i.e while traversing adj nodes. We mark it after we are done with all adj nodes.
            // This is different from the way we used it in BFS.
            vis[currNode] = 1;
        }


        // Traverse the parent arr and find wt of nodes indx->parent[indx]. Add this wt in totalCost of spanning tree.
        for(int i=1;i<V;i++)
        {
            int firstNode = i, secNode = parent[i];
            vector<vector<int>> reqVec = adj[firstNode];
            
            for(int j=0;j<reqVec.size();j++)
            {
                if(reqVec[j][0] == secNode)
                {
                    totalCost += reqVec[j][1];
                    break;
                }
            }
        }
        

        return totalCost;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
