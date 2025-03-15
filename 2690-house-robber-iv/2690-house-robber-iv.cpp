class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canRob(nums, mid, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
private:
    bool canRob(const vector<int>& nums, int max_val, int k) {
        int count = 0;
        int prev = -2; // Track the last robbed index
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= max_val && i > prev + 1) {
                count++;
                prev = i;
                if (count >= k) return true;
            }
        }
        return count >= k;
    }
};
