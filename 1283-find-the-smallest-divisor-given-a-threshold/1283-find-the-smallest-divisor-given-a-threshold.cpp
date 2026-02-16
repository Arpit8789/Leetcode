class Solution {
public:
    bool ispossible(int mid,vector<int>& nums, int threshold)
    {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=ceil(double(nums[i])/mid);
        }
        if(sum<=threshold)
            return true;
        else
            return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1;
        int ans=0;
        int e=*max_element(nums.begin(),nums.end());
        int mid=s+(e-s)/2;
        while(s<=e)
        {
            if(ispossible(mid,nums,threshold))
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
        return mid;
    }
};