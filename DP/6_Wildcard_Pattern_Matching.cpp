// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/

    int helper(string pattern, string str, int i, int j, vector<vector<int>> &memo)
    {
        // If both strings over then all characters matched.
        if(j<0 && i<0)
            return 1;
        
        // If pattern string still remaining and other string over then...
        if(j<0 && i>=0)
        {
            // See if remaining patern string only has *. If no then strings won't match else match.
            for(int x=i;x>=0;x--)
                if(pattern[x] != '*')
                    return 0;
            return 1;
        }
        
        // If pattern string over and other string still remaining then it's not match.
        if(j>=0 & i<0)
            return 0;

        if(memo[i][j] != -1)
            return memo[i][j];
        
        if(pattern[i] == str[j] || pattern[i] == '?')
        {
            memo[i][j] = helper(pattern, str, i-1, j-1, memo);
            return memo[i][j];
        }
        
        if(pattern[i] == '*')
        {
            memo[i][j] = helper(pattern, str, i-1, j , memo) || helper(pattern, str, i, j-1, memo);
            return memo[i][j];
        }
        
        memo[i][j] = 0;
        return memo[i][j];
        
    }
    
    int wildCard(string pattern,string str)
    {
        int pLen = pattern.length();
        int sLen = str.length();
        
        vector<vector<int>> memo(pLen,vector<int> (sLen,-1));
        
        return helper(pattern, str, pLen-1, sLen-1, memo);
        
    }
};

// { Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}
  // } Driver Code Ends
