class Solution {
public:
    bool isPalindrome(int x) {
        long long rev = 0;  // bigger type for safety
        int num = x;
        if(num<0)
        {
            return false;
        }
        
        while (num != 0) {
            int d = num % 10;
            rev = rev * 10 + d;
            
            // check overflow
            if (rev > INT_MAX || rev < INT_MIN) {
                return false; // as per LeetCode rule
            }
            num /= 10;
        }
        
        if(rev==x)
            return true;
        else
            return false;
        
    }
};