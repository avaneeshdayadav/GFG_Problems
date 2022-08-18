class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        long long cnt = 0;
        long long n = nums.size();
        
        // If j-i == nums[j] - nums[i] then it will be a good pair
        // We can write it as j - nums[j] == i - nums[i]
        // Total numbers of pairs where i<j is n(n-1)/2
        
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
            mp[i-nums[i]]++;
        
        for(auto it: mp)
        {
            long long num = it.second;
            
            // sum of first num terms where 1st term is 0.
            long long sum = num*(num-1)/2;
            cnt += sum;
        }
        
        return (long long)(n*(n-1)/2) - cnt;
    }
    
};
