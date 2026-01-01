class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx, vector<int>& nums, vector<int>& temp) {
        // Condition 1: size should be at least 2
        if (temp.size() >= 2) {
            ans.push_back(temp);
        }

        // Used to avoid duplicates at the same recursion level
        unordered_set<int> used;

        // Similar to subset generation using for-loop
        for (int i = idx; i < nums.size(); i++) {

            // Duplicate check at same level
            if (used.count(nums[i])) continue;

            // Order check: non-decreasing condition
            if (temp.empty() || nums[i] >= temp.back()) {
                used.insert(nums[i]);
                temp.push_back(nums[i]);

                solve(i + 1, nums, temp);

                temp.pop_back(); // backtrack
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        solve(0, nums, temp);
        return ans;
    }
};
