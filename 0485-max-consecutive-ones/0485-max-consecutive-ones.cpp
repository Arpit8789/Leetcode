class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;    // Tracks maximum consecutive 1s
        int currentCount = 0; // Tracks current streak of 1s
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                currentCount++;
                maxCount = max(maxCount, currentCount);
            } else {
                currentCount = 0;
            }
        }
        
        return maxCount;
    }
};
