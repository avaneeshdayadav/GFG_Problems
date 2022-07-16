// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        pair<int,int> src,dest;
        int n = grid.size();
        int m = grid[0].size();
        
        // Find source and destination.
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    src.first = i;
                    src.second = j;
                }
                
                if(grid[i][j] == 2)
                {
                    dest.first = i;
                    dest.second = j;
                }
            }
        }
        
        queue<pair<int,int>> q;
        q.push(src);
        vector<vector<int>> vis(n,vector<int> (m,0));
        vis[src.first][src.second] = 1;

        while(!q.empty())
        {
            pair<int,int> f = q.front();
            q.pop();
            
            int x = f.first;
            int y = f.second;
            
            if(grid[x][y] == 2)
            {
                return true;
            }

            // Explore the adj Nodes.
            
            // go right and see if it's (blank or dest) and not visited.
            if(y+1<m && grid[x][y+1] >= 2 && !vis[x][y+1])
            {
                vis[x][y+1] = 1;
                q.push({x,y+1});
            }
            
            // go left and see if it's (blank or dest) and not visited.
            if(y-1>=0 && grid[x][y-1] >= 2 && !vis[x][y-1])
            {
                vis[x][y-1] = 1;
                q.push({x,y-1});
            }
            
            // go up and see if it's (blank or dest) and not visited.
            if(x-1>=0 && grid[x-1][y] >= 2 && !vis[x-1][y])
            {
                vis[x-1][y] = 1;
                q.push({x-1,y});
            }
            
            // go down and see if it's (blank or dest) and not visited.
            if(x+1<n && grid[x+1][y] >= 2 && !vis[x+1][y])
            {
                vis[x+1][y] = 1;
                q.push({x+1,y});
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends
