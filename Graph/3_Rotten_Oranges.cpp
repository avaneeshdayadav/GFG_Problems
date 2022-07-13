// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        
        int row = grid.size(), col = grid[0].size(), orangeCnt = 0;
        queue<pair<int,int>> q;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j] == 2)
                    q.push({i,j});
                
                if(grid[i][j] == 1)
                    orangeCnt++;     
            }
        }
        
        int time = 0;
        while(!q.empty() and orangeCnt>0)
        {
            int currQsize = q.size();
            for(int i=0;i<currQsize;i++)
            {
                pair<int,int> front = q.front();
                q.pop();
                
                int x = front.first, y = front.second;

                if(x-1 >= 0 && grid[x-1][y] == 1)
                {
                    q.push({x-1,y});
                    grid[x-1][y] = 2;
                    orangeCnt--;
                }
                    
                
                if(y-1 >= 0 && grid[x][y-1] == 1)
                {
                    orangeCnt--;
                    grid[x][y-1] = 2;
                    q.push({x,y-1});
                }
                    
                
                if(x+1 < row && grid[x+1][y] == 1)
                {
                    orangeCnt--;
                    grid[x+1][y] = 2;
                    q.push({x+1,y});
                }
                    
                
                if(y+1 < col && grid[x][y+1] == 1)
                {
                    orangeCnt--;
                    grid[x][y+1] = 2;
                    q.push({x,y+1});
                }      
            }
            time++;
        }
        
        if(orangeCnt != 0)
            return -1;
        
        return time;
        
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
