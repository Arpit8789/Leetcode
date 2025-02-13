class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         if (nums.empty()) return 0; // Edge case: empty array
        
        int k = 1; // Index for the next unique element
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i]; // Place unique element at index k
                k++; // Move the unique index forward
            }
        }
        return k;
        
    }
};