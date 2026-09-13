class Solution{
public:
    bool helper(vector<int>& stones,vector<vector<int>>& dp,int i,int k){
        if(i==stones.size()-1)
            return true;
        if(dp[i][k]!=-1)
            return dp[i][k];

        bool a=false,b=false,c=false;

        for(int j=i+1;j<stones.size();j++){
            if(stones[j]==stones[i]+k-1)
                a=helper(stones,dp,j,k-1);
            if(stones[j]==stones[i]+k)
                b=helper(stones,dp,j,k);
            if(stones[j]==stones[i]+k+1)
                c=helper(stones,dp,j,k+1);
        }

        return dp[i][k]=a||b||c;
    }

    bool canCross(vector<int>& stones){
        int n=stones.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return helper(stones,dp,0,0);
    }
};