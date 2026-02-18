class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0;
        int ans=0;
        int e=nums.size()-1;
        if(nums[nums.size()-1]<target)
            return nums.size();
        
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]>=target)
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }

        }
        return ans;
    }
};