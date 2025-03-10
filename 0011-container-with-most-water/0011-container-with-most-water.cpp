class Solution {
public:
    int maxArea(vector<int>& height) {
        int sz= height.size();
        int s=0;
        int e=sz-1;
        long hold=0;
        long mini=0;
        long narea=0;
        while(s<e)
        {
            //if (height[s]<height[e]?mini=height[s]:mini=height[e]);
            mini=min(height[s],height[e]);
            narea=(e-s)*mini;
            hold=max(hold,narea);
            if(mini==height[s])
            {
                s++;
            }
            else
            {
                e--;
            }

            

        }
        return hold;
        
    }
};