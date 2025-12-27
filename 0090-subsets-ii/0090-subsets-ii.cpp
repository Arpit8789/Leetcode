class Solution {
private:
    void solve(vector<int> nums,vector<vector<int>>& ans,vector<int> v,int i,int n)
    {
        if(i>=n)
        {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        solve(nums,ans,v,i+1,n);
        v.pop_back();
        int nxtind=i+1;
        while(nxtind<n && nums[nxtind]==nums[i])
        {
            nxtind++;
        }
        solve(nums,ans,v,nxtind,n);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        int i=0,n=nums.size();
        sort(nums.begin(),nums.end());
        solve(nums,ans,v,i,n);
        return ans;
    }
};