class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // Time O(N) space O(1)
        
        // we assume that our first element is the majority element so it's currently a winning candidate.
        int winningCandidate = nums[0];
        
        
        // votes decides the priority of a winning candidate. The more the occurence of the candidate, the more it's priority (votes) increases. If another candidate occurs we reduce the votes of current winning candidate.
        int votes = 1;
        
        
        
        for(int i=1;i<nums.size();i++)
        {
            // If our choosen winning candidate (element) is occured again increase it's priority by increasing its votes.
            if(nums[i] == winningCandidate)
                votes++;
            // Else if some other candidate (occured) occured.
            else
            {
                // If current winning canditdate still has some votes left decrease it's votes as some other candidate occured and will cancel it's votes.
                if(votes > 0)
                    votes--;
                // If current elements votes are nullified then this new candidate might be our winner, so set this candidate as new winning candidate and it's vote is set to 1.
                else
                {
                    votes = 1;
                    
                    winningCandidate = nums[i];
                }
            }
        }
        
        // Happy return whoever is the winning candidate. :)
        return winningCandidate;
        
    }
};
