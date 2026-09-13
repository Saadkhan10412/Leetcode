class Solution{
public:
    bool canCross(vector<int>& stones){
        int n=stones.size();
        vector<vector<int>> dp(n,vector<int>(n+1,false));
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
            mp[stones[i]]=i;

        for(int k=0;k<=n;k++)
            dp[n-1][k]=true;

        for(int i=n-2;i>=0;i--){
            for(int k=0;k<=n;k++){
                if(k-1>0&&mp.find(stones[i]+k-1)!=mp.end())
                    dp[i][k]=dp[i][k]||dp[mp[stones[i]+k-1]][k-1];

                if(k>0&&mp.find(stones[i]+k)!=mp.end())
                    dp[i][k]=dp[i][k]||dp[mp[stones[i]+k]][k];

                if(k+1<=n&&mp.find(stones[i]+k+1)!=mp.end())
                    dp[i][k]=dp[i][k]||dp[mp[stones[i]+k+1]][k+1];
            }
        }

        return dp[0][0];
    }
};