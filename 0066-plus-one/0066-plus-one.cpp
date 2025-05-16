class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Start from the end and process carry
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;     // No carry-over needed
                return digits;
            }
            digits[i] = 0;       // Set current digit to 0 and carry to the next
        }

        // If all digits were 9, we need an extra digit at the beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
