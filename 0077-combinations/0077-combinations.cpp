class Solution {
private:
    void solve(vector<int>& nums,vector<vector<int>>& ans,vector<int>& v,int k,int i)
    {
        if ( v.size() == k) {
            ans.push_back(v);
            return;
        }

       
        if ( v.size() > k || i >= nums.size()) {
            return;
        }
        v.push_back(nums[i]);
       
        solve(nums,ans,v,k,i+1);
        v.pop_back();
        solve(nums,ans,v,k,i+1);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        int i=0,sum=0;
        vector<int> nums;
        for(int j=1;j<=n;j++)
        {
            nums.push_back(j);
        }
        solve(nums,ans,v,k,i);
        return ans;
    }
};