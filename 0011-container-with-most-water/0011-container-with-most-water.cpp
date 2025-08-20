class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int maxi=0,mini=0;
        int area=1;
        while(l<=r)
        {
            mini=min(height[l],height[r]);
            area=mini*(r-l);
            maxi=max(maxi,area);
            if(height[l]<height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return maxi;
        
    }
};