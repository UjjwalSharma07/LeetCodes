class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int leftprice = prices[0];
        int maxprofit = 0;
        for(int i=1; i<prices.size(); i++){
            leftprice = min(leftprice,prices[i]);
            maxprofit = max(maxprofit,prices[i]-leftprice);
        }
        return maxprofit;
    }
};