class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        // Brute Force.
//             sort(nums.begin(),nums.end());
//             int cnt = 0,sub = 0;
//             for(int i=0;i<nums.size();i++)
//             {
//                 if(nums[i] == 0)
//                     continue;

//                 sub = nums[i];
//                 for(int j = i;j<nums.size();j++)
//                 {
//                     nums[j] -= sub;
//                 }
//                 cnt++;
//             }

//             return cnt;
        
        
        // No of different elements = no. of operations required.
            unordered_set<int> s;
            for(auto i:nums) if(i!=0) s.insert(i);
            return s.size();
    }
};
