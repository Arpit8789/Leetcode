class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_set<int> unique_elements(nums.begin(), nums.end()); // Get unique elements
        int n = nums.size();

        for (int elem : unique_elements) { 
            int count = 0;
            for (int num : nums) {
                if (num == elem) count++;
            }
            if (count > n / 2) return elem; // Majority element condition
        }

        return -1; // This case won't occur as per the problem guarantee
    }
};

