class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int sz=nums.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<sz;i++)
        {
            mpp[nums[i]]++;
        }
        for(auto it:mpp)
        {
            if(it.second>1)
            {
                return true;
            }
        }
        return false;
    }
};