class Solution {
public:
    int helper(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>& dp){
        if(i>=matrix.size() || j<0 || j>=matrix[0].size()){
            return INT_MAX;
        }
        if(i==matrix.size()-1){
            return dp[i][j]=matrix[i][j];
        }
        if(dp[i][j]!=101){
            return dp[i][j];
        }
        int a=helper(matrix,i+1,j-1,dp);
        int b=helper(matrix,i+1,j,dp);
        int c=helper(matrix,i+1,j+1,dp);
        return dp[i][j]=matrix[i][j]+min(a,min(b,c));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,101));
        int ans=INT_MAX;
        for(int j=0;j<m;j++){
            ans=min(ans,helper(matrix,0,j,dp));
        }
        return ans;
    }
};