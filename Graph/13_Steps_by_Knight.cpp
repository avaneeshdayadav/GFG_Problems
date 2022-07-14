#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&knightPos,vector<int>&targetPos,int N)
	{
	    // Code here
        targetPos[0] -= 1;
        targetPos[1] -= 1;
        
        knightPos[0] -= 1;
        knightPos[1] -= 1;
        
        queue<pair<int,int>> q;
        vector<vector<int>> vis(N,vector<int>(N,0));
        q.push({knightPos[0],knightPos[1]});
        int lvl=0;
        
        while(!q.empty())
        {
            int qSize = q.size();
            for(int i=0;i<qSize;i++)
            {
                pair<int,int> f = q.front();
                q.pop();
                int x = f.first;
                int y = f.second;
                
                
                if(x == targetPos[0] && y == targetPos[1])
                {
                    return lvl;
                }
                
                // check all possible neighbour.
                if(y+2 < N && x-1 >= 0 && !vis[x-1][y+2])
                {
                    q.push({x-1,y+2});
                    vis[x-1][y+2] = 1;
                }
                if(y+2 <N && x+1 < N && !vis[x+1][y+2])
                {
                    q.push({x+1,y+2});
                    vis[x+1][y+2]=1;
                }
                if(y-2>=0 && x-1>=0 && !vis[x-1][y-2])
                {
                    q.push({x-1,y-2});
                    vis[x-1][y-2] = 1;
                }
                if(y-2>=0 && x+1 <N && !vis[x+1][y-2])
                {
                    q.push({x+1,y-2});
                    vis[x+1][y-2]=1;
                }
                if(x+2<N && y+1<N && !vis[x+2][y+1])
                {
                    q.push({x+2,y+1});
                    vis[x+2][y+1]=1;
                }
                if(x+2<N && y-1>=0 && !vis[x+2][y-1])
                {
                    q.push({x+2,y-1});
                    vis[x+2][y-1]=1;
                }
                if(x-2>=0 && y-1>=0 && !vis[x-2][y-1])
                {
                    q.push({x-2,y-1});
                    vis[x-2][y-1] = 1;
                }
                if(x-2>=0 && y+1<N && !vis[x-2][y+1])
                {
                    vis[x-2][y+1]=1;
                    q.push({x-2,y+1});
                }
            }
            lvl++;
        }
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
