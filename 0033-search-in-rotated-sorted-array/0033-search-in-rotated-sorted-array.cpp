class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,ans=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                return ans;
            }
            if(nums[mid]>=nums[l])
            {
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1; // target lies in left half
                } else {
                    l = mid + 1; // target lies in right half
                }
            }
            else
            {
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1; // target lies in right half
                } else {
                    r = mid - 1; // target lies in left half
                }

            }
        }
        return ans;
    }
};