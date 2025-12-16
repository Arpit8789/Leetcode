class Solution {
private:
    void solve(vector<int> nums, vector<vector<int>>& ans1, int n, int i) {
        if (i >= n) {
            ans1.push_back(nums);
            return;
        }

        unordered_set<int> used_value;

        for (int j = i; j < n; j++) {
            if (used_value.count(nums[j])) continue;
            used_value.insert(nums[j]);

            swap(nums[i], nums[j]);
            solve(nums, ans1, n, i + 1);
            swap(nums[i], nums[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size(), i = 0;
        vector<vector<int>> ans1;
        sort(nums.begin(), nums.end());
        solve(nums, ans1, n, i);
        return ans1;
    }
};
