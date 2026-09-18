class Solution {
public:
    int helper(vector<int>& nums,int i,int n,vector<int>& dp){
        if(i>n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take=nums[i]+helper(nums,i+2,n,dp);
        int nottake=helper(nums,i+1,n,dp);

        return dp[i]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<2){
            return nums[0];
        }
        vector<int> dp(nums.size(),-1);
        int a=helper(nums,0,nums.size()-2,dp);
        for(int i=0;i<dp.size();i++){
            dp[i]=-1;
        }
        int b=helper(nums,1,nums.size()-1,dp);
        return max(a,b);
    }
};