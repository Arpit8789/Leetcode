class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz=nums.size();
        int p=0;
        int q=0;
        int ctr=0;
        for(int j=0;j<sz;j++)
        {
            if(nums[j]==0)
                ctr++;
        }
        if(ctr!=0)
        {
            while(p<sz)
            {
                if(nums[p]!=0)
                {
                
                    swap(nums[p],nums[q]);
                    q++;

                }
                p++;
            }
        }
    }
};