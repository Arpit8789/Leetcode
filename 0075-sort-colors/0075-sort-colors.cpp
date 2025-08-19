class Solution {
public:
    void sortColors(vector<int>& nums) {
        int sz=nums.size();
        int cnt1=0,cnt2=0,cnt3=0;
        for(int j=0;j<sz;j++)
        {
            if(nums[j]==0)
                cnt1++;
            else if(nums[j]==1)
                cnt2++;
            else
                cnt3++;
        }
        int k=0;
        while(k<cnt1)
        {
            nums[k]=0;
            k++;
        }
        while(k<(cnt2+cnt1))
        {
            nums[k]=1;
            k++;
        }
        while(k<(cnt1+cnt2+cnt3))
        {
            nums[k]=2;
            k++;
        }
        
    }
};