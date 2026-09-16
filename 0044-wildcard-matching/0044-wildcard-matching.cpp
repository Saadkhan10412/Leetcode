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
            for(int k=j;k<p.size();k++){
                if(p[k]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool a=false,b=false,c=false;
        if(s[i]==p[j] || p[j]=='?'){
            a=helper(s,p,i+1,j+1,dp);
        }
        if(p[j]=='*'){
            b=helper(s,p,i+1,j,dp);
            c=helper(s,p,i,j+1,dp);
        }
        return dp[i][j]=a||b||c;
    }
    bool isMatch(string s,string p){
        vector<vector<int>> dp(s.size(),vector<int>(p.size(),-1));
        return helper(s,p,0,0,dp);
    }
};