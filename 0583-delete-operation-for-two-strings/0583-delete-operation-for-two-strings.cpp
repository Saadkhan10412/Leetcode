class Solution {
public:
    int helper(string& word1,string& word2,int i,int j,vector<vector<int>>& dp){
        if(i==word1.size()||j==word2.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]==word2[j]){
            return dp[i][j]=1+helper(word1,word2,i+1,j+1,dp);
        }
        int a=helper(word1,word2,i+1,j,dp);
        int b=helper(word1,word2,i,j+1,dp);
        return dp[i][j]=max(a,b);
    }

    int minDistance(string word1,string word2) {
        int m=word1.size();
        int n=word2.size();
        if(m==0) return n;
        if(n==0) return m;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int lcs=helper(word1,word2,0,0,dp);
        return m+n-2*lcs;
    }
};