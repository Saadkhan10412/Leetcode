class Solution {
public:
    int helper(vector<vector<int>>& triangle,int n,int m, int i, int j,vector<vector<int>>& dp){
        if(i==n-1){
            return dp[i][j]=triangle[i][j];
        }
        if(dp[i][j]!=1e4+1){
            return dp[i][j];
        }
        int a=helper(triangle,n,m,i+1,j,dp);
        int b=helper(triangle,n,m,i+1,j+1,dp);
        return dp[i][j]=triangle[i][j]+min(a,b);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,1e4+1));
        return helper(triangle,n,n,0,0,dp);
    }
};