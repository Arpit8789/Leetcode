#include <vector>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        
        // Find the first positive number using binary search
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        int negativeCount = left; // Number of negative elements
        
        // Find the first zero or positive number using binary search
        left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        int positiveCount = n - left; // Number of positive elements
        
        return max(negativeCount, positiveCount);
    }
};
