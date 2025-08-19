class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sz=nums.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<sz;i++)
        {
            mpp[nums[i]]++;
        }
        for(auto it:mpp)
        {
            if(it.second>sz/2)
            {
                return it.first;
            }
        }
        return 1;
    }
};