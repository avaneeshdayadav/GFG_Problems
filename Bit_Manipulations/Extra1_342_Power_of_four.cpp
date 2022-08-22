class Solution {
public:
    bool isPowerOfFour(int n) {
        
        // Observe that for power of four, there is only one set bit and it should be at odd place from left.
        
        int pos = 1, i=1, no_of_set_bits = 0;
        
        while(n > 0)
        {
            if(n & 1)
            {
                no_of_set_bits++;
                pos = i;
            }
            i++;
            n = n >> 1;
        }
        
        return (no_of_set_bits == 1) && (pos & 1);
    }
};
