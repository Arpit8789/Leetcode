class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int ans=-1;
        int e=nums.size()-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                return ans;;
            }
            //left is sorted
            else if(nums[mid]>=nums[s])
            {
                if(nums[mid]>target && nums[s]<=target)
                    e=mid-1;
                else
                    s=mid+1;

            }
            //right is sorted
            else 
            {
                if(nums[mid]<target && nums[e]>=target)
                    s=mid+1;
                else
                    e=mid-1;
            }
        }
        return ans;
    }
    
};