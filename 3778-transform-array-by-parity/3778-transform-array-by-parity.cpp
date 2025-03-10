class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int temp=0;
        int s=nums.size();
        for(int i=0; i<s;i++)
        {
            if(nums[i]%2==0)
            {
                nums[i]=0;
            }
            else
            {
                nums[i]=1;
            }
        }
        for(int i=0;i<s;i++)
        {
            for(int j=0;j<s-1;j++)
            {
                if(nums[j]>nums[j+1])
                {
                    temp=nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=temp;
                }
            }
        }
        return nums;
    }
};