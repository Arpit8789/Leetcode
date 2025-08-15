class Solution {
public:
    void reverseArray(vector<int>& nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;

        k %= n; // handle k > n
        if (k == 0) return; // no rotation needed

        // Step 1: Reverse last k elements
        reverseArray(nums, n - k, n - 1);

        // Step 2: Reverse first n-k elements
        reverseArray(nums, 0, n - k - 1);

        // Step 3: Reverse whole array
        reverseArray(nums, 0, n - 1);
    }
};
