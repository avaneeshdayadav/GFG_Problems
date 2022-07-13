// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int levelOfX(int V, vector<int> adj[], int X) {
	    // Code here
	    
	    vector<int> vis(V,0);
	    queue<int> q;
	    int lvl = 0;
	    
	    q.push(0);
	    int i =  1;
	    while(!q.empty())
	    {
	        
	        int qSize = q.size();
	        
	        for(int i=0;i<qSize;i++)
	        {
	            int front = q.front();
	            q.pop();
    	        if(front == X)
    	            return lvl;
    	            
    	        if(vis[front] == 0)
    	        {
    	            vis[front] = 1;
    	            
    	            for(int i=0;i<adj[front].size();i++)
    	            {
    	                q.push(adj[front][i]);
    	            }
    	            
    	        }
	        }
	        lvl++;
	        
	        
	    }
	    
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
          int u, v;
          cin >> u >> v;
          adj[u].push_back(v);
          adj[v].push_back(u);
        }
        int X;
        cin >> X;
        Solution obj;
        cout<<obj.levelOfX(V,adj,X)<<endl;
	}
	return 0;
}  // } Driver Code Ends
