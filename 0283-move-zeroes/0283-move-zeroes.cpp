class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=0;
        int sz=nums.size();
        while(j<sz)
        {
            if(nums[j]!=0 && nums[i]==0)
            {
                swap(nums[i],nums[j]);
                i++;
            }
            if(nums[j]==0 && nums[i]!=0)
                i=j;
            j++;
        }
        
        
    }
};