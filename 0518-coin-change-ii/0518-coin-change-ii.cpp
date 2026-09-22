class Solution {
public:
    int helper(int amount, vector<int>& coins,int i,vector<vector<int>>& dp){
        if(amount==0){
            return 1;
        }
        if(amount<0){
            return 0;
        }
        if(i==coins.size()){
            return 0;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int notTake = helper(amount, coins, i+1, dp);
        int take = 0;

        if(coins[i] <= amount) {
            take = helper(amount-coins[i], coins, i, dp);
        }
        return dp[i][amount] =take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1, -1));
        return helper(amount,coins,0,dp);
    }
};