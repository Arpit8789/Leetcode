class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = -1, sum = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] >= 0) {
                cnt++;
                sum += nums[i];
                maxi = max(sum, maxi);
            } else {
                sum = 0;
            }
        }
        if (cnt < 1) {
            int maxVal = *max_element(nums.begin(), nums.end());
            return maxVal;
        }
        return maxi;
    }
};