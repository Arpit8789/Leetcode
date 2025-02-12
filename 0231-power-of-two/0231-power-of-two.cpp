class Solution {
public:
    bool isPowerOfTwo(int n) {
        for (int i=0;i<=30;i++)
        {
            int two=pow(2,i);
            if(two==n)
            {
                return true;

            }
            
        }
    return false;    
    }
};