class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int st=0,ed=n-1;
        while(st<=ed)
        {
            int mid=st+(ed-st)/2;
            if((mid==0 || nums[mid]!=nums[mid-1]) && (mid==n-1 || nums[mid]!=nums[mid+1]))
                return nums[mid];
            if(nums[mid]==nums[mid-1])
            {
                if(mid%2==0)
                    ed=mid-2;
                else
                    st=mid+1;
            }
            else if(nums[mid]==nums[mid+1])
            {
                if(mid%2!=0)
                    ed=mid-1;
                else
                    st=mid+2;
            }
        }
        return -1;
    }
};
