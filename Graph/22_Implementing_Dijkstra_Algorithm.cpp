// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Minheap has pair of {minDist_req_to_reach_this_node_till_now, NodeName}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        
        // Dist array to store min distance to reach every node.
        vector<int> dist(V,INT_MAX),vis(V,0);
        dist[S] = 0;
        
        // Source Node dist from source node is 0.
        minHeap.push({0,S});
        
        
        // We can do this without visited array also. Just keep looping till minHeap is not empty.
        while(!minHeap.empty())
        {
            pair<int,int> top = minHeap.top();
            int nodeName = top.second;
            int weight = top.first;
            minHeap.pop();
            
            // Look on all the adj's nodes of this poped node.
            for(auto it : adj[nodeName])
            {
                if(!vis[it[0]])
                {
                    int adjNodeName = it[0];
                    int adjNodeWt = it[1];
                    
                    // Push in Heap only if the minDist of a adj node is getting updated. So all adj nodes from this adj node can be evaluated again.
                    if(weight + adjNodeWt < dist[adjNodeName])
                    {
                        dist[adjNodeName] = weight + adjNodeWt;
                        minHeap.push({dist[adjNodeName],adjNodeName});
                    }
                }
            }
            vis[nodeName] = 1;
        }
        
        return dist;
        
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends
