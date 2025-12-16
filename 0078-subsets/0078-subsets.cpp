class Solution {
private:
    void solve(vector<int>& nums,int i,int n,vector<int> ans,vector<vector<int>>& ans1)
    {
        if(i>=n)
        {
            ans1.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        solve(nums,i+1,n,ans,ans1);
        ans.pop_back();
        solve(nums,i+1,n,ans,ans1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int i=0,n=nums.size();
        vector<vector<int>> ans1;
        vector<int> ans;
        solve(nums,i,n,ans,ans1);
        return ans1;
    }
};