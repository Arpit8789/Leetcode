class Solution {
public:
    double rec(double x, int n)
    {
        if(n==0)
            return 1;
        double half=rec(x,n/2);
        if(n%2==0)
        {
            return half*half;
        }
        else
        {
            return half*half*x;
        }
        
    }
    double myPow(double x, int n) {
        long long m=n;
        if(m<0)
        {
            x=1/x;
            m=-m;
        }
        return rec(x,m);
    }
};