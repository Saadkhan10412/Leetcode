class Solution {
public:
    int helper(vector<vector<int>>& grid,int n,int m,int i, int j,vector<vector<int>>& dp){
        if(i>=n || j>=m ){
            return 1e9;
        }
        if(i==n-1 && j==m-1){
            return dp[i][j]=grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a =helper(grid,n,m,i+1,j,dp);
        int b=helper(grid,n,m,i,j+1,dp);
        return dp[i][j] = grid[i][j]+min(a,b);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(grid,n,m,0,0,dp);
    }
};