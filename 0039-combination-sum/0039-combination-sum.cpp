class Solution {
private:
    void solve(vector<int> nums, int target,vector<vector<int>>& ans,vector<int> v,int i,int sum,int n)
    {
        if(i>=n || sum>target)
        {
            return;
        }
        if(sum==target)
        {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        sum+=nums[i];
        solve(nums,target,ans,v,i,sum,n);
        v.pop_back();
        sum-=nums[i];
        solve(nums,target,ans,v,i+1,sum,n);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        int i=0,sum=0,n=candidates.size();
        solve(candidates,target,ans,v,i,sum,n);
        return ans;
    }
};