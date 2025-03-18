class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int result = 0;
        for (int num : nums) {  // Corrected for-loop syntax
            result ^= num;  
        }
        return result;
    }
};
