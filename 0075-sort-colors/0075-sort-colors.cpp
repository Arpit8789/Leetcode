class Solution {
public:
    void sortColors(vector<int>& nums) {
        int sz=nums.size();
        int ctr=0, ctr1=0, ctr2=0;
        nums.erase(nums.begin(),nums.end());
        for(int i=0;i<sz;i++)
        {
            if(nums[i]==0)
            {
                ctr++;
            }
            else if(nums[i]==1)
            {
                ctr1++;
            }
            else
            {
                ctr2++;
            }
        }
        int j=0;
        while(j<ctr)
        {
            nums.push_back(0);
            j++;
        }
        j=0;
        while(j<ctr1)
        {
            nums.push_back(1);
            j++;
        }
        j=0;
        while(j<ctr2)
        {
            nums.push_back(2);
            j++;
        }
        
    }
};