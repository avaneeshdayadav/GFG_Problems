#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[N], vis(N,0), reccSt(N,0);
        
        for(int i=0;i<prerequisites.size();i++)
        {
            int to = prerequisites[i].first;
            int from = prerequisites[i].second;
            adj[from].push_back(to);
        }

    
    
        for(int i=0;i<N;i++)
        {
            if(!vis[i])
            {
                if(DFScycle(adj,vis,reccSt,i))
                    return false;
            }
        }
	   
	    return true;
    
	}
	
	bool DFScycle(vector<int> adj[], vector<int> &vis, vector<int> &reccSt, int node)
	{
	    vis[node] = reccSt[node] = 1;
	    
	    for(auto it : adj[node])
	    {
	        if(!vis[it])
	        {
	            if(DFScycle(adj,vis,reccSt,it))
	                return true;
	        }
	        else if(reccSt[it])
	            return true;
	    }
	    reccSt[node] = 0;
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends
