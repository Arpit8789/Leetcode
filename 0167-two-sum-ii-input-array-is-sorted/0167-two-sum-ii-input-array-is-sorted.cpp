class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;

        while (l < r) {
            int sum = numbers[l] + numbers[r];

            if (sum == target) {
                // +1 because the problem usually expects 1-based indexing
                return {l + 1, r + 1};
            }
            else if (sum < target) {
                l++; // move left pointer right to increase sum
            }
            else {
                r--; // move right pointer left to decrease sum
            }
        }
        return {}; // no solution (though problem guarantees one exists)
    }
};
