class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        for(int i=0;i<m+1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<n+1;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<m+1;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<n+1;i++){
            dp[0][i]=1;
        }
        for(int i=2;i<m+1;i++){
            for(int j=2;j<n+1;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return abs(dp[m][n]);
    }
};