// Initial Template for C

// Program to count islands in boolean 2D matrix
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define COL 501


 // } Driver Code Ends
// User function Template for C


void dfs(int grid[][COL], int i, int j, int n, int m)
{
    if(grid[i][j] == 0 || grid[i][j] == -1)
        return;
    
    grid[i][j] = -1;
    
    if(i+1 < n && j < m && grid[i+1][j] == 1)
        dfs(grid,i+1,j,n,m);
    if(i < n && j+1 < m && grid[i][j+1] == 1)
        dfs(grid,i,j+1,n,m);
    if(i < n && j-1 >= 0 && grid[i][j-1] == 1)
        dfs(grid,i,j-1,n,m);
    if(i-1 >= 0 && j < m && grid[i-1][j] == 1)
        dfs(grid,i-1,j,n,m);
        
    // Diagonal checks.
    if(i+1 < n && j+1 < m && grid[i+1][j+1] == 1)
        dfs(grid,i+1,j+1,n,m);
    if(i-1 >=0 && j-1 >= 0 && grid[i-1][j-1] == 1)
        dfs(grid,i-1,j-1,n,m);
    if(i-1 >=0 && j+1 < m && grid[i-1][j+1] == 1)
        dfs(grid,i-1,j+1,n,m);
    if(i+1 < n && j-1 >= 0 && grid[i+1][j-1] == 1)
        dfs(grid,i+1,j-1,n,m);
}


int countIslands(int grid[][COL], int n, int m) {
    // your code goes here
    int compCnt = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            // cout<<i<<" "<<j<<endl;
            if(grid[i][j] == 1)
            {
                compCnt++;
                // cout<<"Hello"<<endl;
                dfs(grid,i,j,n,m);
            }
        }
    }
    
    return compCnt;
}





// { Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {

        int n, m;
        scanf("%d %d", &n, &m);

        int M[n][COL];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &M[i][j]);
            }
        }

        int ans = countIslands(M, n, m);
        printf("%d\n", ans);
    }

    return 0;
}
  // } Driver Code Ends
