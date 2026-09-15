class Solution {
public:
    int minDistance(string word1,string word2) {
        int m=word1.size();
        int n=word2.size();

        if(m==0) return n;
        if(n==0) return m;

        vector<vector<int>> dp(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            if(word1[i]==word2[0]){
                dp[i][0]=1;
            }else if(i>0){
                dp[i][0]=dp[i-1][0];
            }
        }

        for(int j=0;j<n;j++){
            if(word1[0]==word2[j]){
                dp[0][j]=1;
            }else if(j>0){
                dp[0][j]=dp[0][j-1];
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(word1[i]==word2[j]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int lcs=dp[m-1][n-1];

        return m+n-2*lcs;
    }
};