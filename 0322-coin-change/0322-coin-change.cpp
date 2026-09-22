class Solution {
public:
    int helper(vector<int>& coins,int i,int money,vector<vector<int>>&dp,int amount){
        if(money==amount){
            return 0;
        }
        if(i==coins.size() || money>amount){
            return INT_MAX;
        }
        if(dp[i][money]!=-1){
            return dp[i][money];
        }
        int take=INT_MAX;
        if(money<=amount-coins[i]){
            int x=helper(coins,i,money+coins[i],dp,amount);
            if(x!=INT_MAX){
                take=1+x;
            }
        }
        int nottake=helper(coins,i+1,money,dp,amount);
        return dp[i][money]=min(take,nottake);
    }
    int coinChange(vector<int>& coins,int amount){
        if(amount==0){
            return 0;
        }
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans=helper(coins,0,0,dp,amount);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};