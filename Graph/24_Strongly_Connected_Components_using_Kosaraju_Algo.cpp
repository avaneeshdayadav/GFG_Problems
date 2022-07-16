// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int> vis(V,0);
        
        // st is stack for keeping track of which node finished first.
        // st2 is just a dummy stack bcoz in second part we need to call DFS again which does not req stack but we
        // are using same function of DFS so have to give some dummy stack or need to create some new DFS function
        // for second part.
        stack<int> st,st2;
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
                DFS(adj,V,vis,st,i);
        }
        
        vector<int> transposeOfGraph[V];
        
        // Reverse graph links
        makeTranspose(adj,transposeOfGraph,V);
        
        // Re initialize vis vector.
        for(int i=0;i<V;i++)
            vis[i] = 0;
        
        // cnt to count no.of strongly connected componenets.
        int cnt = 0;
        
        // Apply DFS in order of finish time. Start from one which finish last in prev traversal. Use stack for that.
        while(!st.empty())
        {
            int top = st.top();
            st.pop();
            if(!vis[top])
            {
                DFS(transposeOfGraph,V,vis,st2,top);
                
                // Count no.of times we are manually calling DFS.
                cnt++;
            }
        }
        
        return cnt;
    }
    
    void DFS(vector<int> adj[], int V, vector<int> &vis, stack<int> &st, int node)
    {
        vis[node] = 1;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
                DFS(adj,V,vis,st,it);
        }
        
        // After all adj nodes discovered push this node in stack to record it's finish time.
        st.push(node);
    }
    
    void makeTranspose(vector<int> adj[], vector<int> transposeOfGraph[], int V)
    {
        for(int i=0;i<V;i++)
        {
            for(auto it : adj[i])
                transposeOfGraph[it].push_back(i);
        }
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
