class Solution {
public:
    bool ispossible(int mid ,vector<int>& nums, int k )
    {
        int ctr=1,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            
            if(sum+nums[i]<=mid)
            {
                sum+=nums[i];
                
            }
            else
            {
                sum=0;
                ctr++;
                sum+=nums[i];
            }
            if(k<ctr)
            {
                return false;
            }
            
            
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int s=*max_element(nums.begin(),nums.end());
        int e=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            e+=nums[i];
        }

        int mid=s+(e-s)/2;
        while(s<=e)
        {
            if(ispossible(mid,nums,k))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};