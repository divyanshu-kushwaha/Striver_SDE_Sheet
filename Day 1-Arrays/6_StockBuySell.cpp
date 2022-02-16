// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n,0);
        
        int min_price = prices[0];
        for(int i = 1; i<n; i++){
            min_price = min(min_price, prices[i]);
            
            int left = prices[i] - min_price; //if we sell on ith day
            int right = dp[i-1];              //if we do not sell on ith day
            
            dp[i] = max(left,right);
        }
        return dp[n-1];
    }
};