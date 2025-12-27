class Solution {
private:
    void solve(vector<int> nums,vector<vector<int>>& ans,vector<int> v,int k,int n,int i,int sum)
    {
        if (sum == n && v.size() == k) {
            ans.push_back(v);
            return;
        }

       
        if (sum > n || v.size() > k || i >= nums.size()) {
            return;
        }
        v.push_back(nums[i]);
       
        solve(nums,ans,v,k,n,i+1,sum+nums[i]);
        v.pop_back();
        solve(nums,ans,v,k,n,i+1,sum);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        int i=0,sum=0;
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        solve(nums,ans,v,k,n,i,sum);
        return ans;
    }
};