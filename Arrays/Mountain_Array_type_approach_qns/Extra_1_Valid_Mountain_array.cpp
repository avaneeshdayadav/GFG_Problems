
// Problem Link ; https://leetcode.com/problems/valid-mountain-array/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        int n=arr.size();
        
        int l=0,r=n-1;
        
        while(l<n-1 && arr[l]<arr[l+1])
            l++;
        
        while(r>0&&arr[r-1]>arr[r])
            r--;

        if(l==r && l>0 && r<n-1)
            return true;
        else
            return false;
    }
};
