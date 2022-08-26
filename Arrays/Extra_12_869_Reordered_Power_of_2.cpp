class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        string num = to_string(n);
        
        sort(num.begin(),num.end());
        
        for(int i=0;i<31;i++)
        {
            string powOf2str = to_string((int)pow(2,i));
            
            sort(powOf2str.begin(), powOf2str.end());
            
            if(powOf2str == num)
                return true;
        }
        
        return false;
        
    }
    
};
