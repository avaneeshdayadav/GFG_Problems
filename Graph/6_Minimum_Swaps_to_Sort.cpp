// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
        // Store given arr with their index.
        vector<pair<int,int>> vec(nums.size());
        for(int i=0;i<nums.size();i++)
            vec[i] = {nums[i],i};
        
        sort(vec.begin(),vec.end());
        
        // Without thinking of graph. O(nlogn) time and O(n) Space.
        // Here we try to converted sorted array to given array and cnt the swaps req.
	       // int cnt = 0;
	       // for(int i=0;i<vec.size();i++)
	       // {
	       //     if(i != vec[i].second)
	       //     {
	       //         swap(vec[i], vec[vec[i].second]);
	       //         i--;
	       //         cnt++;
	       //     }
	           
	       // }
	        
	        
	       // return cnt;
	        
	   // With graph thinking.
    	   vector<int> vis(nums.size(),0);
    	   int ans = 0;
    	   
    	   for(int i=0;i<nums.size();i++)
    	   {
    	       // Either node is not visited or is not at correct place.
    	       if(!vis[i] || vec[i].second != i)
    	       {
    	           int num_of_nodes_in_cycle = 0;
    	           int j = i;
    	           
    	           while(!vis[j])
    	           {
    	               vis[j] = 1;
    	               // move to next node using index.
    	               j = vec[j].second;
    	               
    	               // increase node cnt in cycle.
    	               num_of_nodes_in_cycle++;
    	           }
    	           
    	           if(num_of_nodes_in_cycle > 0)
    	               ans += num_of_nodes_in_cycle - 1;
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
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
