class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n + 1, 0);  // Initialize a vector of size n+1 with all zeros
        
        // Mark present numbers
        for (int num : nums) {
            arr[num] = 1;
        }
        
        // Find the missing number
        for (int i = 0; i <= n; i++) {
            if (arr[i] == 0) {
                return i;
            }
        }
        
        return -1;  // This line should never be reached if the input is valid
    }
};
