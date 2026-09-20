class Solution {
public:
    bool helper(vector<int>& arr,int i,int k,vector<vector<int>>&dp){
        if(k==0){
            return true;
        }
        if(i==arr.size()){
            return false;
        }
        if(k<0){
            return false;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        return dp[i][k]=helper(arr,i+1,k,dp) || helper(arr,i+1,k-arr[i],dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto x:nums){
            sum+=x;
        }
        if(sum%2!=0){
            return false;
        }else{
            int k=sum/2;
            vector<vector<int>>dp(nums.size(),vector<int>(k+1,-1));
            return helper(nums,0,k,dp);
        }
    }
};