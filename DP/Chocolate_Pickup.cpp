int helper(vector<vector<int>>&arr, int i, int j1, int j2, vector<vector<vector<int>>> &memo, vector<int> &dir, int c)
{
    if(j1<0 || j2<0 || j1>=c || j2>=c)
        return INT_MIN;
    
    if(i == arr.size()-1){    
        if(j1 == j2)
            memo[i][j1][j2] = arr[i][j1];
        else
            memo[i][j1][j2] = arr[i][j1] + arr[i][j2];
        
        return memo[i][j1][j2];
    }
    
    if(memo[i][j1][j2] != -1)
        return memo[i][j1][j2];

    int maxim = INT_MIN;
    
    for(int x=0;x<3;x++)
    {
        for(int y=0;y<3;y++)
            maxim = max(maxim, helper(arr, i+1, j1+dir[x], j2+dir[y], memo, dir, c));
    }
    
    
    if(j1 == j2)
        memo[i][j1][j2] = arr[i][j1] + maxim;
    else
        memo[i][j1][j2] = arr[i][j1] + arr[i][j2] + maxim;

    return memo[i][j1][j2];
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    
    vector<vector<vector<int>>> memo(r,vector<vector<int>>(r,vector<int> (c,-1)));
    vector<int> dir = {-1, 0, 1};
    return helper(grid, 0, 0, c-1, memo, dir, c);
    
}
