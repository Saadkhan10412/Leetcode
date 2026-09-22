class Solution {
public:
    int helper(int n,int i,vector<int>&sq,vector<vector<int>>&dp){
        if(n==0){
            return 0;
        }
        if(i==sq.size() || n<0){
            return INT_MAX;
        }
        if(dp[i][n]!=-1){
            return dp[i][n];
        }
        int take=INT_MAX;
        if(sq[i]<=n){
            int x=helper(n-sq[i],i,sq,dp);
            if(x!=INT_MAX){
                take=1+x;
            }
        }
        int nottake=helper(n,i+1,sq,dp);
        return dp[i][n]=min(take,nottake);
    }
    int numSquares(int n) {
        vector<int> sq;
        for(int i=1;i*i<=n;i++){
            sq.push_back(i*i);
        }
        vector<vector<int>> dp(sq.size(),vector<int>(n+1,-1));
        return helper(n,0,sq,dp);
    }
};