// Problem Link : https://leetcode.com/problems/flood-fill/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int x = sr, y = sc;
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0)), ans(image.begin(),image.end());
        
        queue<pair<int,int>>q;
        
        q.push({x,y});
        vis[x][y] = 1;
        
        ans[x][y] = color;
        
        int xCord[4] = {0, 0, 1,-1};
        int yCord[4] = {1,-1, 0, 0};
        while(!q.empty())
        {
            pair<int,int> f = q.front();
            q.pop();
            
            int i = f.first;
            int j = f.second;
            
            
            for(int k=0;k<4;k++)
            {
                if(i+xCord[k] < n && j+yCord[k]<m && i+xCord[k] >=0 && j+yCord[k] >= 0 && !vis[i+xCord[k]][j+yCord[k]] && image[i][j] == image[i+xCord[k]][j+yCord[k]])
                {
                    vis[i+xCord[k]][j+yCord[k]] = 1;
                    ans[i+xCord[k]][j+yCord[k]] = color;
                    q.push({i+xCord[k], j+yCord[k]});
                }
            }
        }
        
        return ans;
        
    }
};
