class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz=prices.size();
        int mini=INT_MAX,maxi=0;
        for(int i=0;i<sz;i++)
        {
            mini=min(prices[i],mini);
            maxi=max(maxi,prices[i]-mini);
        }
        return maxi;
        
    }
};