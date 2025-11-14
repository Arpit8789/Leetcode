class Solution {
public:
    int trap(vector<int>& height) {
        int sz=height.size();
        int p=0;
        int q=sz-1;
        int maxl=0,maxr=0,wtrap=0;
        while(p<=q)
        {
            if(height[p]<=height[q])
            {
                if (height[p] >=maxl) {
                    maxl = height[p]; 
                } else {
                    wtrap += maxl - height[p]; 
                }
                p++;
            }
            else
            {
                if(height[q]>= maxr)
                {
                    maxr = height [q];
                }
                else
                {
                    wtrap+= maxr-height[q];
                }
                
                q--;
            }
            
        }

        return wtrap;
    }
};


