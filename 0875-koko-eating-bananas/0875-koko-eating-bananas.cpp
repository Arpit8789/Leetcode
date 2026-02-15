class Solution {
public:
    bool ispossible(int mid,vector<int>& piles, int h)
    {
        int hcount=0;
        int leftout=0;
        for(int i=0;i<piles.size();i++)
        {
            hcount += ceil((double)piles[i] / mid);
            if(hcount>h)
                return false;
        }
        return true;   
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int sz=piles.size();
        int ans=0;
        int s=1;
        int e=*max_element(piles.begin(),piles.end());
        int mid=s+(e-s)/2;
        while(s<=e)
        {
            if(ispossible(mid,piles,h))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};