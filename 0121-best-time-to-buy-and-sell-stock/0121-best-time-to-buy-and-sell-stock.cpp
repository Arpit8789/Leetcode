class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int MSP=prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--){
            res=max(res,MSP-prices[i]);
            MSP=max(MSP,prices[i]);
        }
        return res;
    }
};