class Solution {
public:
    bool helper(string& s,string& p,int i,int j,vector<vector<int>>& dp){
        if(i==s.size() && j==p.size()){
            return true;
        }
        if(j==p.size()){
            return false;
        }
        if(i==s.size()){
            if(j+1<p.size() && p[j+1]=='*'){
                return helper(s,p,i,j+2,dp);
            }
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool a=false,b=false;
        if(j+1<p.size() && p[j+1]=='*'){
            if(s[i]==p[j] || p[j]=='.'){
                a=helper(s,p,i+1,j,dp);
            }
            b=helper(s,p,i,j+2,dp);
        }
        else if(s[i]==p[j] || p[j]=='.'){
            a=helper(s,p,i+1,j+1,dp);
        }
        return dp[i][j]=a||b;
    }
    bool isMatch(string s,string p){
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        return helper(s,p,0,0,dp);
    }
};