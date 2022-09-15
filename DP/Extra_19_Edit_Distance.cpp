int helper(string &s1, string &s2, int i, int j, vector<vector<int>> &memo)
{
    if(i<0)
        return j+1;
    if(j<0)
        return i+1;
    
    if(memo[i][j] != -1)
        return memo[i][j];
    
    if(s1[i] == s2[j])
    {
        memo[i][j] = helper(s1,s2,i-1,j-1,memo);
        return memo[i][j];
    }
    
    int insert = helper(s1,s2,i,j-1,memo);
    int del = helper(s1,s2,i-1,j,memo);
    int replace = helper(s1,s2,i-1,j-1,memo);
    
    memo[i][j] = 1 + min(insert,min(del,replace));
    return memo[i][j];
}
int editDistance(string str1, string str2)
{
    //write you code here
    int n1 = str1.length();
    int n2 = str2.length();
    
    vector<vector<int>> memo(n1,vector<int> (n2,-1));
    return helper(str1,str2,n1-1,n2-1,memo);
}
