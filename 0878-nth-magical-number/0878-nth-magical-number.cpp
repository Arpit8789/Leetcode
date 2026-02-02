class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        const long long MOD = 1e9 + 7;

        long long g = __gcd(a, b);
       
        long long lcm = (1LL * a * b) / g;

        long long low = min(a, b);
        long long high = 1LL * n * min(a, b);

        while (low < high) {
            long long mid = low + (high - low) / 2;

            long long count =
                mid / a +
                mid / b -
                mid / lcm;

            if (count < n) {
                low = mid + 1;   
            } else {
                high = mid;      
            }
        }

        return low % MOD;
    }
};
