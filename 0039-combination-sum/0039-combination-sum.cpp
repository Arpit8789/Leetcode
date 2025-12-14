class Solution {
private:
    void solve(vector<vector<int>> &ans,
               vector<int> &v,
               vector<int> &candidates,
               int target,
               int i)
    {
        // valid combination
        if (target == 0) {
            ans.push_back(v);
            return;
        }

        // out of bounds or target exceeded
        if (i >= candidates.size() || target < 0) {
            return;
        }

        // PICK the element (can reuse same index)
        v.push_back(candidates[i]);
        solve(ans, v, candidates, target - candidates[i], i);
        v.pop_back();

        // NOT PICK the element (move to next index)
        solve(ans, v, candidates, target, i + 1);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(ans, v, candidates, target, 0);
        return ans;
    }
};
