class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;
        
        k %= n; // Normalize rotation steps
        if (k == 0) return;
        
        // Three-step reversal using two pointers
        reverse(nums, 0, n-1);    // Reverse entire array
        reverse(nums, 0, k-1);    // Reverse first k elements
        reverse(nums, k, n-1);    // Reverse remaining elements
    }
    
private:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};
