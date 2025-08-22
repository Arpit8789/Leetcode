class Solution {
    public int searchInsert(int[] nums, int target) {
        int l = 0, r = nums.length - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                return mid; // found target
            } else if (target < nums[mid]) {
                r = mid - 1; // move left
            } else {
                l = mid + 1; // move right
            }
        }

        // if not found, l is the correct insert position
        return l;
    }
}
