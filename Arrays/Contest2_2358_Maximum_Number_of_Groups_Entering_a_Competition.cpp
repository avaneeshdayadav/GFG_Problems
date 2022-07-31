class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        // sort(grades.begin(),grades.end());
        int cnt = 0, n = grades.size();
        
        if(n == 1)
            return 1;
        
        // O(n) Time
            // for(int i=1;i<n;i++)
            // {
            //     if((i*(i+1))/2 <= n)
            //         cnt++;
            //     else
            //         break;
            // }
            // return cnt;
        
        
        // O(logn) Time using binary search
            // int left = 0, right = 1000;
            // while (left < right) {
            //     int k = (left + right + 1) / 2;
            //     if (k * (k + 1) / 2 > n) {
            //         right = k - 1;
            //     } else {
            //         left = k;
            //     }
            // }
            // return left;
        
        
        
        // O(1) Time using math formula
        // Derivation of formula
            // 1 + 2 + ... + k <= n
            // k(k + 1) / 2 <= n
            // (k + 0.5)(k + 0.5) <= n * 2 + 0.25
            // k + 0.5 <= sqrt(n * 2 + 0.25)
            // k <= sqrt(n * 2 + 0.25) - 0.5
        
            return (int)(sqrt(n * 2 + 0.25) - 0.5);
        

        
    }
};
