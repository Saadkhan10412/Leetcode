class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size()+2));
        for(int i=0;i<matrix[0].size();i++){
            dp[0][i+1]=matrix[0][i];
        }
        for(int i=0;i<matrix.size();i++){
            dp[i][0]=1e4;
        }
        for(int i=0;i<matrix.size();i++){
            dp[i][dp[0].size()-1]=1e4;
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size()+1;j++){
                dp[i][j]=matrix[i][j-1]+min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1]));
            }
        }
        int ans=INT_MAX;
        for(int i=1;i<dp[0].size()-1;i++){
            ans=min(ans,dp[dp.size()-1][i]);
        }
        return ans;
    }
};