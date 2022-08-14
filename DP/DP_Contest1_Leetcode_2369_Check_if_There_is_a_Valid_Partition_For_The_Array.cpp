class Solution {
public:
    bool validPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        // Dp array for memoizing our calculated result. (Nothing to do with name 'dp'. Feel free to give any name.)
        vector<int> dp(n,-1);
        
        // Call our Kind helper function to compute the result and tell if it's possible to get valid partition starting from index 0.
        return helper(nums, dp, 0, n);
    }
    
    
    
    bool helper(vector<int> &arr, vector<int> &dp, int start_indx, int n)
    {
        // If we reached last index then return a very Happy True :)
        if(start_indx >= n)
            return true;
        
        // If we have already calculated the return value of helper function for this start_indx value, then return calculated value happily :)
        if(dp[start_indx] != -1)
            return dp[start_indx];
        
        
        // If this arr element at index = start_indx and the next element both are same then enter inside this if block.
        if(start_indx + 1 < n && arr[start_indx] == arr[start_indx + 1])
        {
            // Now call helper for remaining elements, 2 step ahead from current start_index.
			//If helper return true enter this if block.
            if(helper(arr, dp, start_indx + 2, n))
            {
                // Store true i.e 1 inside dp array at this start_indx position for future use (memoizing the result).
				// This shows that it's possible to get a valid array from this start_indx. 
                dp[start_indx] = 1;
                
                // Happily return true :)
                return true;
            }
            
            // If we did not returned true from above block then we see if three elements of array are same.
			// If yes enter this if block.
            if(start_indx + 2 < n && arr[start_indx] == arr[start_indx +2])
            {
                // Call helper again for starting index equal to 3 steps ahead of this current start_indx.
				// If helper return true enter this if block.
                if(helper(arr, dp, start_indx + 3, n))
                {
                    // As helper returned true, store true i.e 1 inside dp array at this start_indx for future (memoizing  the result).
					//This shows that it's possible to get a valid array from this start_indx.
                    dp[start_indx] = 1;
                    
                    // Happily return true :)
                    return true;
                }
            }
        }
        
        
        // If neither 2 elements or 3 elements same then check if 3 consecutive elements of array are in A.P.
		// If yes then enter this if block.
        if(start_indx + 2 < n && arr[start_indx + 1] - arr[start_indx] == 1 && arr[start_indx+2] - arr[start_indx] == 2)
        {
            // Call helper for starting index equal to 3 steps ahead from current start_indx. If helper returns true enter the block.
            if(helper(arr, dp, start_indx+3, n))
            {
                // As usual memoize the result of helper in dp at start_in
                dp[start_indx] = 1;
                
                // Happily return true :)
                return true;
            }
        }
        
        
        // If your code has arrived here that means none of the conditions were true or none of the calls to helper above has returned true.
		// Sadly that means from this start_index of array we cannot find any valid partition.   -_-
        
        // But we still have to store this info inside our dp array so that next time if someone calls helper at this start_index, tell them not to do any calculation.
		// We already know we cannot find partition from this start_indx of the array. So store 0 i.e false at this index of dp array.
        dp[start_indx] = 0;
        
        
        // Sad to return false but return it anyway :(
        return false;
    }
    
};
