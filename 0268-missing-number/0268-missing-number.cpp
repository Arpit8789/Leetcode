class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mpp;

        for (int i = 0; i <= n; i++) {
            mpp[i] = 0;
        }

        
        for (int num : nums) {
            mpp[num] = 1; 
        }

        
        for (auto it : mpp) {
            if (it.second == 0) {
                return it.first;
            }
        }

        return -1;
    }
};
