class Solution {
public:
    const int MOD = 1e9 + 7;

    // Fast modular exponentiation
    long long power(long long x, long long n) {
        long long result = 1;
        x %= MOD;
        while (n > 0) {
            if (n % 2 == 1)
                result = (result * x) % MOD;
            x = (x * x) % MOD;
            n /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even_count = (n + 1) / 2;
        long long odd_count = n / 2;

        long long evenWays = power(5, even_count);
        long long oddWays = power(4, odd_count);

        return (evenWays * oddWays) % MOD;
    }
};
