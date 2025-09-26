class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();        
        int p=0,q=n-1;
        int lmax=0,rmax=0,water_trapped =0;
        while(p<=q)
        {
            if(height[p]<=height[q])
            {
                if (height[p] >= lmax) {
                    lmax = height[p]; 
                } else {
                    water_trapped += lmax - height[p]; 
                }
                p++;
            }
            else
            {
                if(height[q]>= rmax)
                {
                    rmax = height[q]; 
                } else {
                    water_trapped += rmax - height[q]; 
                }
                
                q--;
            }
            
        }
        return water_trapped;

    }
};