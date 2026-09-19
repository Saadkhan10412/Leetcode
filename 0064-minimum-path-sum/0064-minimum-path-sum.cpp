class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size()+1,vector<int>(grid[0].size()+1));
        for(int i=0;i<=grid.size();i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=grid[0].size();j++){
            dp[0][j]=0;
        }
        dp[1][1]=grid[0][0];
        for(int i=1;i<=grid.size();i++){
            for(int j=1;j<=grid[0].size();j++){
                if(i==1&&j==1){
                    continue;
                }
                else if(i==1){
                    dp[i][j]=grid[i-1][j-1]+dp[i][j-1];
                }
                else if(j==1){
                    dp[i][j]=grid[i-1][j-1]+dp[i-1][j];
                }else{
                    dp[i][j]=grid[i-1][j-1]+min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[grid.size()][grid[0].size()];
    }
};