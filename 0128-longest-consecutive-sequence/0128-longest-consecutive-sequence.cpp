class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        sort(nums.begin(),nums.end());
        int cnt=0,maxi=0;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]==nums[i])
                continue;
            else if((nums[i+1]-nums[i])==1)
            {
                cnt++;
            }
            
            else
            {
                
                cnt=0;
            }
            maxi=max(cnt,maxi);
            
        }
        return maxi+1;
    }
};