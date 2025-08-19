class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v,p,n;
        int sz=nums.size();
        for(int i=0;i<sz;i++)
        {
            if(nums[i]<0)
            {
                n.push_back(nums[i]);
            }
            else
            {
                p.push_back(nums[i]);
            }
        }
        int x=0;
        for(int j=0;j<sz;j++)
        {
            if(j%2==0)
                v.push_back(p[x]);
            else
            {
                v.push_back(n[x]);
                x++;
            }
        }
        return v;
    }
};