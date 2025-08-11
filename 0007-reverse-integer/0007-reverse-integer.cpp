class Solution {
public:
    int reverse(int x) {
        long long rev = 0;  // bigger type for safety
        int num = x;
        
        while (num != 0) {
            int d = num % 10;
            rev = rev * 10 + d;
            
            // check overflow
            if (rev > INT_MAX || rev < INT_MIN) {
                return 0; // as per LeetCode rule
            }
            num /= 10;
        }
        return (int)rev;
    }
};
