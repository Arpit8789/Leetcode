class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0,rsum=0,maxsum=0;
        for(int i=0;i<=k-1;i++)
        {
            lsum=lsum+cardPoints[i];
            maxsum=lsum;
        }
        
        int n=cardPoints.size();
        int rindex=n-1;
        for(int j=k-1;j>=0;j--)
        {
            lsum=lsum-cardPoints[j];
            rsum=rsum+cardPoints[rindex];
            rindex=rindex-1;
            maxsum=max(maxsum,lsum+rsum);
        }
        return maxsum;
        
    }
};