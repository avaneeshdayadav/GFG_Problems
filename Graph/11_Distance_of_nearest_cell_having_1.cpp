#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int row = grid.size();
	    int col = grid[0].size();
	    
	    vector<vector<int>> ans(row,vector<int>(col));
	    queue<pair<int,int>> q;
	    
	    for(int i=0;i<row;i++)
	    {
	        for(int j = 0;j<col;j++)
	        {
	            if(grid[i][j] == 0)
	                ans[i][j] = INT_MAX - 1;
	            else
	            {
	                q.push({i,j});
	                ans[i][j] = 0;
	            }
	        }
	    }
	    
	    while(!q.empty())
	    {
	        pair<int,int> front = q.front();
	        int x = front.first;
	        int y = front.second;
	        q.pop();
	        
	        // Check all adj's
	        
	        if(x+1 < row)
	        {
	            if((ans[x+1][y] > ans[x][y]+1))
	            {
	                ans[x+1][y] = ans[x][y]+1;
	                q.push({x+1,y});
	            }
	        }
	        if(x-1 >= 0)
	        {
	            if((ans[x-1][y] > ans[x][y]+1))
	            {
	                ans[x-1][y] = ans[x][y]+1;
	                q.push({x-1,y});
	            }
	        }
	        if(y-1 >= 0)
	        {
	            if((ans[x][y-1] > ans[x][y]+1))
	            {
	                ans[x][y-1] = ans[x][y]+1;
	                q.push({x,y-1});
	            }
	        }
	        if(y+1 < col)
	        {
	            if((ans[x][y+1] > ans[x][y]+1))
	            {
	                ans[x][y+1] = ans[x][y]+1;
	                q.push({x,y+1});
	            }
	        }
	            
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends
